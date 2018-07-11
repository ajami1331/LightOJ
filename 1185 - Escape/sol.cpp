#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 2e5 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, m, cs, ans;
vector < int > G[sz];
int vis[105][2];

void dfs( int u, int c, int f ) {
        if( f ) vis[u][c] = cs;
        for( const int& v: G[u] ) if( vis[v][c ^ 1] != cs ) {
                dfs( v, c ^ 1, 1 );
        }
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<m; i++ ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        G[ x ].push_back( y );
                        G[ y ].push_back( x );
                }

                dfs( 1, 0, 0 );

                ans = 0;

                for( int i=1; i<=n; i++ ) ans += ( vis[i][0] == cs );

                printf( "Case %d: %d\n", cs, ans );

                for( int i=0; i<=n; i++ ) G[i].clear();

        }
 
        return 0;
}
