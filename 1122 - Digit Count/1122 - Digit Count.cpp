#include <bits/stdc++.h>
using namespace std;

int dp[11][11];
int ar[11];
int n, m;

int rec( int ii, int jj ) {
    if( jj == 1 ) return 1;
    if( dp[ii][jj] != -1 ) return dp[ii][jj];
    dp[ii][jj] = 0;
    for( int i=0; i<m; i++ ) {
        if( abs( ar[ii] - ar[i] ) <= 2 ) {
            dp[ii][jj] += rec( i, jj-1 );
        }
    }
    return dp[ii][jj];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs;
    long long res;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &m, &n );
        for( int i=0; i<m; i++ ) {
            scanf( "%d", ar + i );
        }
        memset( dp, -1, sizeof dp );
        res = 0;
        for( int i=0; i<m; i++ ) {
            res += rec( i, n );
        }
        printf( "Case %d: %lld\n", cs, res );
    }
    return 0;
}
