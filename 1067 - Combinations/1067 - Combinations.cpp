#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int sz = 1e6 + 10;
const ll mod = 1000003LL;
ll fac[sz];

void pre() {
    fac[0] = 1LL;
    for( int i=1; i<sz; i++ ) fac[i] = ( fac[i-1] * i ) % mod;
}

ll big_mod( ll b, ll p ) {
    ll ret = 1;
    for( ; p; p >>= 1 ) {
        if( p&1 ) ret = ( ret * b ) % mod;
        b = ( b * b ) % mod;
    }
    return ret % mod;
}

ll mod_inv( ll b ) {
	return big_mod( b, mod - 2 );
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    pre();
    int t, cs;
    int n, r;
    ll up, down;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &r );
        up = fac[n];
        down = ( fac[r] * fac[n-r] ) % mod;
        down = mod_inv( down );
        up *= down;
        up %= mod;
        printf( "Case %d: %lld\n", cs, up );
    }
    return 0;
}
