#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll sz = 1e4 + 10;
int t, n, w, cs;
int p[105], c[105], z[105];
int dp[sz];

int solve( int W ) {
        memset( dp, 0, sizeof dp );
        for( int i=0; i<n; i++ ) {
                for( int j=z[i]; j<=W; j++ ) {
                        dp[j] = max( dp[j], dp[j - z[i]] + p[i] );
                }
        }
        return dp[W];
}

int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &w );

                int sum = 0;

                for( int i=0; i<n; i++ ) {
                        scanf( "%d %d %d", &p[i], &c[i], &z[i] );
                        sum += c[i] * z[i];
                }

                printf( "Case %d: ", cs );
                if( sum <= w ) printf( "%d\n", solve( w - sum ) );
                else printf( "Impossible\n" );

        }
        return 0;
}
