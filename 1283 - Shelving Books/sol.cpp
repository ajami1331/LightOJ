#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n;
int ar[105], br[105];
signed char dp[105][105][105];
int ans;

signed char rec( int x, int a, int b ) {
        if( x == n ) return 0;
        signed char& ret = dp[x][a][b];
        if( ~ret ) return ret;
        ret = 0;
        ret = rec( x + 1, a, b );
        if( ar[x] >= a && ar[x] <= b ) ret = max( ret, (signed char)( 1 + rec( x + 1, ar[x], b ) ) );
        if( ar[x] >= a && ar[x] <= b ) ret = max( ret, (signed char)( 1 + rec( x + 1, a, ar[x] ) ) );
        return ret;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<n; i++ )  {
                        scanf( "%d", &ar[i] );
                        br[i] = ar[i];
                }

                sort( br, br + n );

                for( int i=0; i<n; i++ ) {
                        ar[i] = lower_bound( br, br + n, ar[i] ) - br;
                }

                memset( dp, -1, sizeof dp );
                
                ans = rec( 0, 0, 100 );

                printf( "Case %d: %d\n", cs, ans );

        }
 
        return 0;
}
