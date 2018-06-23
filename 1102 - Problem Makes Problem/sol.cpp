#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 2e6 + 10;
const ll mod = 1000000007;

int n, k;
ll fac[sz];


ll big_mod( ll b, ll p ) {
        ll ret = 1;
        for( ; p>0; p >>= 1 ) {
                if( p&1 ) ret = ( ret * b ) % mod;
                b = ( b * b ) % mod;
        }
        return ret % mod;
}

ll mod_inv( ll b ) {
        return big_mod( b, mod - 2 );
}

ll nCr( int n, int r ) {
        ll a = fac[n];
        ll b = fac[r];
        ll c = fac[n - r];
        ll d = mod_inv( ( b * c ) % mod );
        return ( a * d ) % mod;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        fac[0] = 1;

        for( int i=1; i<sz; i++ ) fac[i] = ( fac[i - 1] * i ) % mod;

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &k );

                printf( "Case %d: %lld\n", cs, nCr( n + k - 1, n ) );

        }

        return 0;
}