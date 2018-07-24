#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 105;
const ll mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
        return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int t, cs;
int n, fl, penguins;
double d;
double x[sz], y[sz];
int c[sz], m[sz];

const int INF = 1e9;

double dist( double a, double b, double c, double d ) {
        return sqrt( sqr( a - c ) + sqr( b - d ) );
}


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

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %lf", &n, &d );

                penguins = 0;

                Dinic flow_graph( n + n + 1 );

                for( int i=1; i<=n; i++ ) {
                        scanf( "%lf %lf %d %d", &x[i], &y[i], &c[i], &m[i] );
                        penguins += c[i];
                }

                for( int i=1; i<=n; i++ ) {
                        flow_graph.add_edge( i, i + n, m[i] );
                        flow_graph.add_edge( 0, i, c[i] );
                }

                for( int i=1; i<=n; i++ ) {
                        for( int j=1; j<=n; j++ ) {
                                if( i == j ) continue;
                                if( cmp( dist( x[i], y[i], x[j], y[j] ), d ) != 1 ) {
                                        flow_graph.add_edge( i + n, j, INF );
                                        flow_graph.add_edge( j + n, i, INF );
                                }
                        }
                }

                fl = 0;

                printf( "Case %d:", cs );

                for( int i=1; i<=n; i++ ) {
                        flow_graph.clear_flow();
                        if( flow_graph.max_flow( 0, i ) == penguins ) printf( " %d", i - 1 ), fl = 1;
                }

                if( !fl ) printf( " -1" );

                printf( "\n" );
        }

        return 0;
}
