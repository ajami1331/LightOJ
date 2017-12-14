#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
const int sz = 1e5 + 10;
int t, n, k, cs;
unsigned long long dp[32][32][905];

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r", stdin );
    #endif /// CLown1331
    for( int i=1; i<31; i++ ) {
        for( int j=1; j<31; j++ ) {
            dp[i][j][0] = 1;
        }
    }
    for( int i=1; i<31; i++ ) {
        for( int j=1; j<31; j++ ) {
            for( int k=1; k<31; k++ )  {
                if( k > i || k > j ) dp[i][j][k] = 0;
                else if( j == 1 ) dp[i][j][k] = i;
                else dp[i][j][k] = i * dp[i - 1][j - 1][k - 1] + dp[i][j - 1][k];
            }
        }
    }
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &k );
        printf( "Case %d: %llu\n", cs, dp[n][n][k] );
    }
    return 0;
}
