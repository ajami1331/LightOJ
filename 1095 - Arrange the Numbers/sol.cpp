#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1005;
const int mod = 1000000007;

#define sqr( a ) ( ( a ) * ( a ) )

ll big_mod( ll b, ll p ) {
        ll ret = 1;
        b %= mod;
        for( ; p>0; p >>= 1 ) {
                if( p&1 ) ret = ( ret * b ) % mod;
                b = ( b * b ) % mod;
        }
        return ret % mod;
}

ll mod_inv( ll b ) {
        return big_mod( b, mod - 2 );
}

int t;
int n, m, k;
ll fac[sz];

ll nCr( int n, int k ) {
        ll a = fac[n];
        ll b = fac[k];
        ll c = fac[n - k];
        ll d = mod_inv( ( b * c ) % mod );
        return ( a * d ) % mod;
}

ll derangement( int n, int k ) {
        ll ret = fac[n];
        for( int i=1; i<=k; i++ ) {
                ret = ( ret + ( ( i & 1 ? -1ll : 1ll ) * ( ( nCr( k, i ) * fac[ n - i] ) % mod ) ) + mod ) % mod;
        }
        return ret;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331
        
        fac[0] = 1;

        for( int i=1; i<sz; i++ ) fac[i] = ( fac[i - 1] * i ) % mod;

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d %d", &n, &m, &k );

                printf( "Case %d: %lld\n", cs, ( nCr( m, k ) * derangement( n - k, m - k ) ) % mod );
 
        }
 
        return 0;
}
