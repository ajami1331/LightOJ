#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 2e4 + 10;
const ll mod = 1e9 + 7;

double dp[2][sz][2], ans;
int cs, n, m;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {
                
                scanf( "%d %d", &n, &m );

                memset( dp, 0, sizeof dp );

                int x = 3 * m - n;

                int y = m - 2 * n;

                int now = 1;
 
                for( int i=1; i<=n; i++ ) {
                        cerr << i << ": ";
                        for( int j=0; j<=n && j<=y; j++ ) {
                                for( int pr=0; pr<2; pr++ ) {
                                        dp[now][j][pr] = 0.0;
                                        if( j < n ) dp[now][j][pr] = ( dp[now ^ 1][j][0] + ( pr != 0 ) ) * ( ( j ) / ( i * 1.0 ) );
                                        if( j > 0 ) dp[now][j][pr] = ( dp[now ^ 1][j - 1][1] + ( pr != 1 ) ) * ( ( i - j ) / ( i * 1.0 ) );
                                        cerr << j << ".." << dp[now][j][pr] << " ";
                                }
                        }
                        cerr << "\n";
                        now ^= 1;
                }

                ans = dp[now ^ 1][y][0];

                printf( "Case %d: %.6f\n", cs, ans );

        }

        return 0;
}