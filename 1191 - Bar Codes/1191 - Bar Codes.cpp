#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k, m, cs, t;
ll dp[55][55][55];

int main() {
    #ifdef CLown1331
        freopen("in.txt", "r", stdin);
    #endif // CLown1331
    for( m=1; m<=50; m++ ) {
        dp[0][0][m] = 1LL;
        for( int i=1; i<=50; i++ ) {
            for( int j=1; j<=50; j++ ) {
                for( int l=1; l<=m; l++ ) {
                    if( l <= i ) dp[i][j][m] += dp[i-l][j-1][m];
                }
            }
        }
    }
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d", &n, &k, &m );
        printf( "Case %d: %lld\n", cs, dp[n][k][m] );
    }
    return 0;
}
