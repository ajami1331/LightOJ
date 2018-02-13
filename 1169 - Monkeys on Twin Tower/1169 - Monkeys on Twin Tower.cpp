#include <bits/stdc++.h>
using namespace std;

int t, n, cs = 1;
int ar[3][1023];
int tr[3][1023];
int dp[3][1023];
int vi[3][1023];

int rec( int i, int j ) {
        if( j >= n ) return 0;
        if( vi[i][j] == cs ) return dp[i][j];
        vi[i][j] = cs;
        int ret = ar[i][j];
        ret += min( rec( i, j+1 ), rec( i^1, j+1 ) + tr[i][j] );
        return dp[i][j] = ret;
}

int main() {
        #ifdef CLown1331
                freopen("in.txt", "r", stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<2; i++ ) for( int j=0; j<n; j++ ) scanf( "%d", &ar[i][j] );

                for( int i=0; i<2; i++ ) for( int j=0; j<n-1; j++ ) scanf( "%d", &tr[i][j] );

                printf( "Case %d: %d\n", cs, min( rec( 0, 0 ), rec( 1, 0 ) ) );

        }

        return 0;
}
