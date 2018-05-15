#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
using ll = long long;
const ll inf = 1e15;
const ll mod = 1e9 + 7;

const int sz = 5e4 + 10;
int n, m, ch;

struct edge {
        int u, v, cost;
        edge() {}
        edge( int _u, int _v, int _w ) : u(_u), v(_v), cost(_w) {}
        bool operator < (const edge& other) const {
                if( other.cost == this->cost ) {
                        if( other.u == this->u ) {
                                return other.v > this->v;
                        } else {
                                return other.u > this->u;
                        }
                } else {
                        return other.cost < this->cost;
                }
        }
};

vector< edge > edges;
vector < edge > graph;
vector < int > par, cnt, rnk;
vector < pair < int, int > > G[sz];
int N;

void init( int n ) {
        N = n + 1;
        par.resize( N );
        cnt.resize( N );
        rnk.resize( N );
        edges.clear();
        graph.clear();
}

void add_edge( int u, int v, int c ) {
        edges.push_back( edge( u, v, c ) );
}

void make_set() {
        for(int i=0; i<N; i++) {
                par[i] = i;
                cnt[i] = 1;
                rnk[i] = 0;
                G[i].clear();
        }
}

int find_rep( int x ) {
        if(x != par[ x ]) {
                par[ x ] = find_rep( par[ x ] );
        }
        return par[ x ];
}

int kruskal() {
        int ret = 0;
        make_set();
        sort( edges.rbegin(), edges.rend() );
        for( const edge& e : edges ) {
                int u = e.u;
                int v = e.v;
                if( ( u = find_rep( u ) ) != ( v = find_rep( v ) ) ) {
                        if( rnk[ u ] < rnk[ v ] ) {
                                cnt[ v ] += cnt[ u ];
                                par[ u ] = par[ v ];
                        } else {
                                rnk[ u ] = max( rnk[ u ], rnk[ v ] + 1 );
                                cnt[ u ] += cnt[ v ];
                                par[ v ] = par[ u ];
                        }
                        ret += e.cost;
                        graph.push_back( e );
                }
        }
        return ret;
}

int lg[sz];
int lvl[sz];
int table[sz][17];
int mn[sz][17];
int pr[sz];

void dfs( int fr, int u, int dep, int val = 0 ) {
        lvl[u] = dep;
        pr[u] = fr;
        mn[u][0] = val;
        for( const auto& vv: G[u] ) {
                if( fr == vv.first )
                        continue;
                dfs( u, vv.first, dep+1, vv.second );
        }
}

int init_lca( int n ) {
        for( int i=0; i<n; i++ ) {
                table[i][0] = pr[i];
        }
        for( int j=1; ( 1 << j ) < n; j++ ) {
                for( int i=0; i<n; i++ ) {
                        if( table[i][j-1] == -1 )
                                continue;
                        table[i][j] = table[ table[i][j-1] ][j-1];
                        mn[i][j] = max( mn[ table[i][j-1] ][ j-1 ], mn[i][j-1] );
                }
        }
        for( int i=0; i<16; i++ )
                lg[1 << i] = i;
        for( int i=1; i<sz; i++ )
                if( !lg[i] )
                        lg[i] = lg[i-1];
}

int query( int n, int p, int q ) {
        int ret = 0;
        int log;
        if( lvl[p] < lvl[q] )
                swap( p, q );
        log = lg[ lvl[ p ] ];
        for( int i=log; i>=0; i-- ) {
                if( lvl[p] - ( 1 << i ) >= lvl[q] ) {
                        ret = max( ret, mn[ p ][ i ] );
                        p = table[ p ][ i ];
                }
        }
        if( p == q )
                return ret;
        for( int i=log; i>=0; i-- ) {
                if( table[ p ][ i ] != -1 && table[ q ][ i ] != -1 && table[ p ][ i ] != table[ q ][ i ] ) {
                        ret = max( ret, mn[ p ][ i ] );
                        ret = max( ret, mn[ q ][ i ] );
                        p = table[ p ][ i ];
                        q = table[ q ][ i ];
                }
        }
        ret = max( ret, mn[ p ][ 0 ] );
        ret = max( ret, mn[ q ][ 0 ] );
        return ret;
}

int dist( int n, int p, int q ) {
        int lca = query( n, p, q );
        return lvl[p] + lvl[q] - 2 * lvl[lca];
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t, n, m, q, cs;

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                init( n );

                for( int i=0,x,y,w; i<m; i++ ) {
                        scanf( "%d %d %d", &x, &y, &w );
                        add_edge( x, y, w ) ;
                }
                kruskal();
                for( auto e: graph ) {
                        G[e.u-1].push_back( make_pair( e.v-1, e.cost ) );
                        G[e.v-1].push_back( make_pair( e.u-1, e.cost ) );
                }
                for( int i=0; i<n; i++ ) {
                        for( int j=0; j<16; j++ ) {
                                table[i][j] = -1;
                                mn[i][j] = 0;
                        }
                }

                scanf( "%d", &q );

                dfs( -1, 0, 0 );

                init_lca( n );

                printf( "Case %d:\n", cs );

                for( int i=0; i<q; i++ ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        --x, --y;
                        printf( "%d\n", query( n, x, y ) );;
                }


        }
        return 0;
}
