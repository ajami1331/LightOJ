#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;
const int mod = 1000007;

typedef long long ll;

int n, m;
int dp[sz];
int ax[sz];
int t, cs, ans;
int ar[105], cr[105];

int main() {
        #ifdef CLown1331
                freopen("in.txt", "r", stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                fill( dp, dp + 1 + m, 0 );

                ans = 0;

                for( int i=0; i<n; i++ ) scanf( "%d", &ar[i] );

                for( int i=0; i<n; i++ ) scanf( "%d", &cr[i] );

                dp[0] = 1;

                for( int i=0; i<n; i++ ) {
                        fill( ax, ax + 1 + m, 0 );
                        for( int j=ar[i]; j<=m; j++ ) {
                                if( dp[j - ar[i]] == 1 && dp[j] == 0 && ax[j - ar[i]] < cr[i] ) {
                                        dp[j] = 1;
                                        ans++;
                                        ax[j] = ax[j - ar[i]] + 1;
                                }
                        }
                }

                printf( "Case %d: %d\n", cs, ans );

        }

        return 0;
}
