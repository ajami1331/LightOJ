#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e5 + 10;
const ll mod = 1e9 + 7;

vector < int > G[sz];
int ar[sz];
int ans, n;

int dfs( int u, int pr = 0 ) {
        for( const int& v: G[u] ) {
                if( v != pr ) {
                        ar[u] += dfs( v, u );
                }
        }
        ans += abs( ar[u] );
        return ar[u];
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<=n; i++ ) {
                        G[i].clear();
                }

                for( int i=0; i<n; i++ ) {
                        int x, y, v, d;
                        scanf( "%d %d %d", &x, &v, &d );
                        ar[x] = v - 1;
                        for( int j=0; j<d; j++ ) {
                                scanf( "%d", &y );
                                G[ x ].push_back( y );
                                G[ y ].push_back( x );
                        }
                }

                ans = 0;

                dfs( 1 );

                printf( "Case %d: %d\n", cs, ans );

        }

        return 0;
}