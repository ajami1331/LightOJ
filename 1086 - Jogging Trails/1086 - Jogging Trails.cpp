#include <bits/stdc++.h>
using namespace std;

int t, n, m, cs;

int dp[1 << 15];
int ar[15][15];
int cnt[15], ans;

int rec( int mask ) {
        if( __builtin_popcount( mask ) == n ) return 0;
        int &ret = dp[mask];
        if( ~ret ) return ret;
        ret = 1 << 30;
        for( int i=0; i<n; i++ ) if( ( ( mask >> i ) & 1 ) == 0 ) {
                for( int j=0; j<n; j++ ) if( ( ( mask >> j ) & 1 ) == 0 ) {
                        if( i == j ) continue;
                        ret = min( ret, rec( mask | ( 1 << i ) | ( 1 << j ) ) + ar[i][j] );
                }
        }
        return ret;
}

int main() {
        #ifdef CLown1331
                freopen("in.txt", "r", stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                memset( dp, -1, sizeof dp );

                memset( ar, 63, sizeof ar );

                memset( cnt, 0, sizeof cnt );

                ans = 0;

                while( m-- ) {

                        int x, y, w;

                        scanf( "%d %d %d", &x, &y, &w );

                        --x, --y;

                        ar[x][y] = min( w, ar[x][y] );

                        ar[y][x] = ar[x][y];

                        cnt[x]++;

                        cnt[y]++;

                        ans += w;
                }

                for( int via=0; via<n; via++ ) {

                        for( int from=0; from<n; from++ ) {

                                for( int to=0; to<n; to++ ) {

                                        ar[from][to] = min( ar[from][to], ar[from][via] + ar[via][to] );

                                }
                        }
                }

                int mask = 0;

                for( int i=0; i<n; i++ ) if( cnt[i] % 2 == 0 ) mask |= ( 1 << i );

                printf( "Case %d: %d\n", cs, rec( mask ) + ans );

        }

        return 0;
}
