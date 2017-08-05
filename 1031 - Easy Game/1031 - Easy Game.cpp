#include <bits/stdc++.h>
using namespace std;

int t, cs, n;
int ar[101];
int dp[101][101][2];
int vv[101][101][2];

int rec( int i, int j, int k ) {
    if( i > j ) return 0;
    if( vv[i][j][k] == cs ) return dp[i][j][k];
    int &ret = dp[i][j][k];
    vv[i][j][k] = cs;
    int sm = 0;
    if( !k ) {
        sm = 0;
        ret = -1e9;
        for( int l=i; l<=j; l++ ) {
            sm += ar[l];
            ret = max( ret, sm + rec( l+1, j, 1 ) );
        }
        sm = 0;
        for( int l=j; l>=i; l-- ) {
            sm += ar[l];
            ret = max( ret, sm + rec( i, l-1, 1 ) );
        }
    } else {
        sm = 0;
        ret = 1e9;
        for( int l=i; l<=j; l++ ) {
            sm += -ar[l];
            ret = min( ret, sm + rec( l+1, j, 0 ) );
        }
        sm = 0;
        for( int l=j; l>=i; l-- ) {
            sm += -ar[l];
            ret = min( ret, sm + rec( i, l-1, 0 ) );
        }
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) scanf( "%d", &ar[i] );
        printf( "Case %d: %d\n", cs, rec( 0, n-1, 0 ) );
    }
    return 0;
}
