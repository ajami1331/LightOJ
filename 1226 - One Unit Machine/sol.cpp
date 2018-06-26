#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
using ull = unsigned long long;

const int sz = 1e6 + 10;
const ll mod = 1e9 + 7;
#define sqr( a ) ( ( a ) * ( a ) )

int t, n, m, k, ar[sz / 100];
ll fac[sz], ans;

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

ll nCr( int n, int k ) {
        ll a = fac[n];
        ll b = fac[k];
        ll c = fac[n - k];
        ll d = mod_inv( ( b * c ) % mod );
        return ( a * d ) % mod;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        fac[0] = 1;

        for( int i=1; i<sz; i++ ) fac[i] = ( fac[i - 1] * i ) % mod;

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
        
                scanf( "%d", &m );

                n = 0;

                ans = 1;

                for( int i=0; i<m; i++ ) {
                        scanf( "%d", &ar[i] );
                        n += ar[i];
                        if( i > 0 ) {
                                ans = ( ans * nCr( n - 1, ar[i] - 1 ) ) % mod;
                        }
                }

                printf( "Case %d: %lld\n", cs, ans );
        }
 
        return 0;
}
