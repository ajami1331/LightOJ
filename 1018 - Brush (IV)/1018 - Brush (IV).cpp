#include <bits/stdc++.h>
using namespace std;

int xx[22], yy[22], ans;
int n;
int dp[1 << 17];

bool col( int i, int j, int k ) {
    return ((xx[i] - xx[j]) * (yy[k] - yy[j]) - (yy[i] - yy[j]) * (xx[k] - xx[j])) == 0;
}

int rec( int mask ) {
    if( __builtin_popcount( mask ) == n ) return 0;
    int &ret = dp[mask];
    if( ~ret ) return ret;
    ret = 27;
    int i = 0, j = 0, k = 0, h = mask;
    for( i=0; mask & ( 1 << i ); i++ );
    mask |= ( 1 << i );
    for( j=0; j<n; j++ ) {
        if( i == j || mask & ( 1 << j ) ) continue;
        h = mask | ( 1 << j );
        for( k=0; k<n; k++ ) {
            if( k == i || k == j || mask & ( 1 << k ) ) continue;
            if( col( i, j, k ) ) h |= ( 1 << k );
        }
        ret = min( ret, rec( h ) + 1 );
    }
    if( ret == 27 ) ret = 1;
    return ret;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    int t;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) {
            scanf( "%d %d", &xx[i], &yy[i] );
        }
        memset( dp, -1, sizeof dp );
        ans = rec( 0 );
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
