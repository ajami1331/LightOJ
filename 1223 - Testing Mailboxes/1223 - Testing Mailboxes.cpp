#include <bits/stdc++.h>
using namespace std;
 
const int inf = 1 << 30;
 
int dp[105][105][105];
int t, cs;
 
int rec( int k, int l, int r ) {
        if( l > r ) return 0;
        if( k == 1 ) {
                int sum = ( r * ( r + 1 ) ) / 2;
                sum -= ( l * ( l - 1 ) ) / 2;
                return sum;
        }
        int& ret = dp[k][l][r];
        if( ~ret ) return ret;
        ret = inf;
        for( int i=l; i<=r; i++ ) {
                ret = min( ret, max( rec( k - 1, l, i - 1 ), rec( k, i + 1, r ) ) + i );
        }
        return ret;
}
 
int main() {
 
        int n, k;
 
        scanf( "%d", &t );
 
        memset( dp, -1, sizeof dp );

        for( cs=1; cs<=t; cs++ ) {
 
                scanf( "%d %d", &k, &n );
 
                printf( "Case %d: %d\n", cs, rec( k, 1, n ) );
 
        }
 
        return 0;
}