#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 5e4 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, m, cs;
vector < int > G[sz], ans;
int ar[sz];
int lvl[sz][2];
bool vis[sz];

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<n; i++ ) {
                        scanf( "%d", &ar[i] );
                }

                for( int i=0; i+1<n; i++ ) {
                        G[ ar[i] ].push_back( ar[i + 1] );
                        G[ ar[i + 1] ].push_back( ar[i] );
                }

                queue < int > Q;

                Q.push( ar[0] );

                memset( vis, 0, sizeof vis );

                vis[ ar[0] ] = 1;

                lvl[ ar[0] ][ 0 ] = 0;

                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        for( const int& v: G[u] ) {
                                if( !vis[v] ) {
                                        vis[v] = 1;
                                        lvl[v][0] = lvl[u][0] + 1;
                                        Q.push( v );
                                }
                        }
                }

                memset( vis, 0, sizeof vis );

                Q.push( ar[n - 1] );

                vis[ ar[n - 1] ] = 1;

                lvl[ ar[n - 1] ][ 1 ] = 0;

                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        for( const int& v: G[u] ) {
                                if( !vis[v] ) {
                                        vis[v] = 1;
                                        lvl[v][1] = lvl[u][1] + 1;
                                        Q.push( v );
                                }
                        }
                }

                ans.clear();

                Q.push( ar[0] );

                ans.push_back( ar[0] );

                for( int i=0; i<lvl[ ar[n - 1] ][0]; i++ ) {
                        int u = Q.front(); Q.pop();
                        int x = sz;
                        for( const int& v: G[u] ) {
                                if( lvl[v][0] + lvl[v][1] == lvl[ ar[n - 1] ][0] && lvl[v][0] > lvl[u][0] ) {
                                        x = min( x, v );
                                }
                        }
                        Q.push( x );
                        ans.push_back( x );
                }

                printf( "Case %d:\n", cs );

                vis[0] = 0;

                for( const int& x: ans ) {
                        if( vis[0] ) printf( " " );
                        printf( "%d", x );
                        vis[0] = 1;
                }

                printf( "\n" );

                for( int i=0; i<n; i++ ) G[ ar[i] ].clear();

        }
 
        return 0;
}
