#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int ar[505][505], br[505][505];

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    int t, n, m;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        for( int i=1; i<=n; i++ ) {
            for( int j=1; j<=m; j++ ) {
                scanf( "%d", &ar[i][j] );
            }
        }
        for( int i=1; i<=n; i++ ) {
            for( int j=1; j<=m; j++ ) {
                scanf( "%d", &br[i][j] );
            }
        }
        for( int i=1; i<=n; i++ ) {
            for( int j=1; j<=m; j++ ) {
                ar[i][j] += ar[i][j - 1];
            }
        }
        for( int j=1; j<=m; j++ ) {
            for( int i=1; i<=n; i++ ) {
                br[i][j] += br[i - 1][j];
            }
        }
        for( int i=0; i<=n; i++ ) {
            for( int j=0; j<=m; j++ ) {
                if( !i || !j ) dp[i][j] = 0;
                dp[i][j] = max( dp[i - 1][j] + ar[i][j], dp[i][j - 1] + br[i][j] );
            }
        }
        printf( "Case %d: %d\n", cs, dp[n][m] );
    }
    return 0;
}
