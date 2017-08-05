#include <bits/stdc++.h>
using namespace std;

int dp[12][2][95][95];
int len, k;
int ar[12];

int rec( int ind, int mxx, int sm, int dv ) {
    if( ind == len ) {
        return sm == 0 && dv == 0;
    }
    int &ret = dp[ind][mxx][sm][dv];
    if( ~ret ) return ret;
    ret = 0;
    int lim = mxx ? ar[ind] : 9;
    for( int i=0; i<=lim; i++ ) {
        ret += rec( ind + 1, mxx && ( i == lim ), ( sm + i ) % k, ( dv * 10 + i ) % k  );
    }
    return ret;
}

int _do( int x ) {
    len = 0;
    while( x ) {
        ar[len++] = x % 10;
        x /= 10;
    }
    reverse( ar, ar + len );
    memset( dp, -1, sizeof dp );
    return rec( 0, 1, 0, 0 );
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif /// CLown1331
    int t, a, b, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d", &a, &b, &k );
        printf( "Case %d: ", cs );
        if( k > 90 ) {
            printf( "0\n" );
        }
        else {
            ans = _do( b  );
            ans -= _do( a-1 );
            printf( "%d\n", ans );
        }
    }
    return 0;
}
