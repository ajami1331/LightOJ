#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
using ll = long long;
const int sz = 2e5 + 10;
const ll inf = 1e15;
const ll mod = 1e9 + 7;

int t, n, q, cs;

vector < int > G[sz];

int lg[sz];
int lvl[sz];
int table[sz][17];
int par[sz];
int va[sz];

void dfs( int fr, int u, int dep ) {
        lvl[u] = dep;
        par[u] = fr;
        for( const int& v: G[u] ) {
                if( fr == v )
                        continue;
                dfs( u, v, dep+1 );
        }
}

int init( int n ) {
        memset( table, -1, sizeof table );
        for( int i=0; i<n; i++ ) {
                table[i][0] = par[i];
        }
        for( int j=1; ( 1 << j ) < n; j++ ) {
                for( int i=0; i<n; i++ ) {
                        if( table[i][j-1] == -1 )
                                continue;
                        table[i][j] = table[ table[i][j-1] ][j-1];
                }
        }
        for( int i=0; i<17; i++ )
                lg[1 << i] = i;
        for( int i=1; i<sz; i++ )
                if( !lg[i] )
                        lg[i] = lg[i-1];
}

int query( int n, int p, int q ) {
        int log;
        log = lg[ lvl[ p ] ];
        for( int i=log; i>=0; i-- ) {
                if( va[ table[p][i] ] >= q ) {
                        p = table[ p ][ i ];
                }
        }
        return p;
}

int dist( int n, int p, int q ) {
        int lca = query( n, p, q );
        return lvl[p] + lvl[q] - 2 * lvl[lca];
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &q );

                for( int i=0; i<=n; i++ ) G[i].clear();

                va[0] = 1;

                for( int i=1; i<n; i++ ) {
                        int x;
                        scanf( "%d %d", &x, &va[i] );
                        G[ x ].push_back( i );
                }

                dfs( -1, 0, 0 );

                init( n );

                printf( "Case %d:\n", cs );

                while( q-- ) {
                        int x, v;
                        scanf( "%d %d", &x, &v );
                        printf( "%d\n", query( n, x, v ) );
                }
        }

        return 0;
}
