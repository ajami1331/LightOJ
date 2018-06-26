#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
const ll mod = 1000;
#define sqr( a ) ( ( a ) * ( a ) )
 
int t, n, k;

ll big_mod( ll b, ll p ) {
        ll ret = 1;
        for( ; p>0; p >>= 1 ) {
                if( p&1 ) ret = ( ret * b ) % mod;
                b = ( b * b ) % mod;
        }
        return ret % mod;
}

ll solve( ll b, ll p ) {
        double x = p * log10( b );
        x -= (int)x;
        x = pow( 10, x );
        ll ans = x * 100;
        return ans;
}
 
int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%d %d", &n, &k );
 
                printf( "Case %d: %lld %03lld\n", cs, solve( n, k ), big_mod( n, k ) );
 
        }
 
        return 0;
}
