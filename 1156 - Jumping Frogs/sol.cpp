#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 3e5 + 10;
const ll mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )

int t, cs, n, m, ans, lo, mid, hi;

const int INF = 1e9;

struct Edge {
        int from, to, cap, flow, index;
        Edge(int from, int to, int cap, int flow, int index) :
                from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
        int N;
        vector<vector<Edge> > G;
        vector<Edge *> dad;
        vector<int> Q;

        Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

        void add_edge(int from, int to, int cap) {
                G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
                if (from == to) G[from].back().index++;
                G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
        }

        long long blocking_flow(int s, int t) {
                fill(dad.begin(), dad.end(), (Edge *) NULL);
                dad[s] = &G[0][0] - 1;

                int head = 0, tail = 0;
                Q[tail++] = s;
                while (head < tail) {
                        int x = Q[head++];
                        for (int i = 0; i < G[x].size(); i++) {
                                Edge &e = G[x][i];
                                if (!dad[e.to] && e.cap - e.flow > 0) {
                                        dad[e.to] = &G[x][i];
                                        Q[tail++] = e.to;
                                }
                        }
                }
                if (!dad[t]) return 0;

                long long totflow = 0;
                for (int i = 0; i < G[t].size(); i++) {
                        Edge *start = &G[G[t][i].to][G[t][i].index];
                        int amt = INF;
                        for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                                if (!e) {
                                        amt = 0;
                                        break;
                                }
                                amt = min(amt, e->cap - e->flow);
                        }
                        if (amt == 0) continue;
                        for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                                e->flow += amt;
                                G[e->to][e->index].flow -= amt;
                        }
                        totflow += amt;
                }
                return totflow;
        }

        long long max_flow(int s, int t) {
                long long totflow = 0;
                while (long long flow = blocking_flow(s, t))
                        totflow += flow;
                return totflow;
        }

        void clear_flow() {
                for (int i = 0; i < N; ++i)
                        for (int j = 0; j < G[i].size(); ++j)
                                G[i][j].flow = 0;

        }
};

struct nd {
        int x, t;
        nd() {}
        nd( int _x, int _t ) {
                x = _x;
                t = _t;
        }
} nds[105];

int f( int d ) {
        Dinic flow_graph( n + n + 2 );
        int src = n + n;
        int snk = src + 1;
        for( int i=0; i<n; i++ ) {
                if( nds[i].x <= d ) {
                        flow_graph.add_edge( src, i, INF );
                }
                if( m - nds[i].x <= d ) {
                        flow_graph.add_edge( i + n, snk, INF );
                }
                flow_graph.add_edge( i, i + n, nds[i].t ? INF : 1 );
        }
        for( int i=0; i<n; i++ ) {
                for( int j=i+1; j<n; j++ ) {
                        if( abs( nds[i].x - nds[j].x ) <= d ) {
                                flow_graph.add_edge( i + n, j, INF );
                                flow_graph.add_edge( j + n, i, INF );
                        }
                }
        }
        if( d == m ) flow_graph.add_edge( src, snk, INF );
        return flow_graph.max_flow( src, snk ) > 1;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<n; i++ ) {
                        char c;
                        int x;
                        getchar();
                        scanf( "%c-%d", &c, &x );
                        nds[i] = nd( x, c == 'B' );
                }

                lo = 0, hi = m;

                while( hi - lo > 4 ) {
                        mid = ( lo + hi ) / 2;
                        if( f( mid ) ) {
                                hi = mid;
                        }
                        else {
                                lo = mid;
                        }
                }

                for( ; lo<=hi; lo++ ) {
                        if( f( lo ) ) break;
                }
                
                printf( "Case %d: %d\n", cs, lo );
        }

        return 0;
}