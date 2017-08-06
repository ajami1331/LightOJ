#include <bits/stdc++.h>
using namespace std;

const int mod = 100000007;
int dp[2][15005];

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif /// CLown1331
    int t, n, k, s, x;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d", &n, &k, &s );
        memset( dp, 0, sizeof dp );
        dp[0][0] = 1;
        x = 0;
        for( int i=0; i<n; i++ ) {
            x ^= 1;
            dp[x][0] = 0;
            dp[x][1] = 0;
            for( int j=1; j<=s; j++ ) {
                dp[x][j] = ( dp[x ^ 1][j - 1] + dp[x][j - 1] );
                if( dp[x][j] >= mod ) dp[x][j] -= mod;
                if( j >= k ) {
                    dp[x][j] = ( dp[x][j] - dp[x ^ 1][j - k - 1] + mod );
                    if( dp[x][j] >= mod ) dp[x][j] -= mod;
                }
            }
        }
        while( dp[x][s] < 0 ) dp[x][s] += mod;
        printf( "Case %d: %d\n", cs, dp[x][s] % mod );
    }
    return 0;
}
