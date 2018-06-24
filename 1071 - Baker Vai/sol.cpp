#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 105;
const ll mod = 1000007;
const int inf = 1 << 16;

int t, n, m;
int dp[sz][sz][sz];
int ar[sz][sz];

int rec( int x1, int y1, int x2, int y2 ) {
        if( x1 >= n || x2 >= n || y1 >= m || y2 >= m ) return -inf;
        int& ret = dp[x1][y1][y2];
        if( ~ret ) return ret;
        if( x1 == x2 && y1 == y2 ) {
                if( x1 == n-1 && y1 == m-1 ) {
                        return ret = ar[n-1][m-1] + ar[0][0];
                }
                else {
                        return ret = -inf;
                }
        }
        ret = 0;
        ret = max( ret, rec( x1 + 1, y1, x2 + 1, y2 ) );
        ret = max( ret, rec( x1 + 1, y1, x2, y2 + 1 ) );
        ret = max( ret, rec( x1, y1 + 1, x2, y2 + 1 ) );
        ret = max( ret, rec( x1, y1 + 1, x2 + 1, y2 ) );
        ret += ar[x1][y1] + ar[x2][y2];
        return ret;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<n; i++ ) {
                        for( int j=0; j<m; j++ ) {
                                scanf( "%d", &ar[i][j] );
                        }
                }

                memset( dp, -1, sizeof dp );

                printf( "Case %d: %d\n", cs, rec( 1, 0, 0, 1 ) );

        }

        return 0;
}