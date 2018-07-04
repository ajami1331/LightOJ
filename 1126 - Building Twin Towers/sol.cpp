#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 5e5 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, ans;
int dp[2][sz];
int ar[sz];
int sum, nw, pr;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                ans = -1;

                sum = 0;

                for( int i=0; i<n; i++ ) {
                        scanf( "%d", &ar[i] );
                        sum += ar[i];
                }

                memset( dp, -1, sizeof dp );

                dp[0][0] = 0;

                nw = 1;

                pr = 0;

                for( int i=0; i<n; i++ ) {
                        for( int j=0; j<sz; j++ )  {
                                if( dp[pr][j] == -1 ) continue;
                                dp[nw][j] = max( dp[nw][j], dp[pr][j] );
                                dp[nw][ abs( j - ar[i] ) ] = max( dp[nw][ abs( j - ar[i] ) ], max( dp[pr][ abs( j - ar[i] ) ], dp[pr][ j ] + ar[i] ) );
                                dp[nw][ abs( j + ar[i] ) ] = max( dp[nw][ abs( j + ar[i] ) ], max( dp[pr][ abs( j + ar[i] ) ], dp[pr][ j ] + ar[i] ) );
                        }
                        swap( nw, pr );
                }

                ans = max( dp[0][0], dp[1][0] ) / 2;

                if( ans == 0 ) printf( "Case %d: impossible\n", cs );

                else printf( "Case %d: %d\n", cs, ans );

        }
 
        return 0;
}
