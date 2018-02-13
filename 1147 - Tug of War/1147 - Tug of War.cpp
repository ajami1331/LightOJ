#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 100;

int t, n, cs;
long long dp[sz];
int ar[105];
int sum;

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                sum = 0;

                for( int i=0; i<n; i++ ) scanf( "%d", &ar[i] ), sum += ar[i];

                fill( dp, dp + sum + 1, 0 );

                dp[0] = 1;

                int lim = n / 2;

                lim += n & 1;


                for( int i=0; i<n; i++ ) {

                        for( int j=sum; j>=ar[i]; j-- ) {

                                dp[j] |= dp[j - ar[i]] << 1;

                        }

                }

                int j;

                for( j=sum / 2; j>=0; j-- ) {

                        int x = n / 2;
                        int y = n / 2;
                        y += n & 1;

                        if( dp[ j ] & ( 1ll << x ) ) break;
                        if( dp[ j ] & ( 1ll << y ) ) break;

                }

                printf( "Case %d: %d %d\n", cs, j, sum - j );
        }

        return 0;
}
