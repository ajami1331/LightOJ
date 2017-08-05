#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int inf = 1e9;
ll dp[26][155];
ll n, x, h, l, gcd;

ll rec( int i, int j ) {
    if( i == n ) {
        if( j >= x ) return 1;
        return 0;
    }
    if( ~dp[i][j] ) return dp[i][j];
    ll &ret = dp[i][j];
    ret = 0;
    for( int k=1; k<=6; k++ ) {
        ret += rec( i+1, j+k );
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%lld %lld", &n, &x );
        memset( dp, -1, sizeof dp );
        h = rec( 0, 0 );
        l = powl( 6, n );
        gcd = __gcd( h, l );
//        cerr << h << " " << l << "\n";
        h /= gcd;
        l /= gcd;
        if( l == 1 ) printf( "Case %d: %lld\n", cs, h );
        else printf( "Case %d: %lld/%lld\n", cs, h, l );
    }
    return 0;
}
