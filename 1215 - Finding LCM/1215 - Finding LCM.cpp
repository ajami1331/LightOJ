#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 1e5 + 10;
const int lim = 1e5;
int t, cs;
ll a, b, l;

ll __lcm( ll x, ll y ) {
        return ( x / __gcd( x, y ) ) * y;
}

ll solve( ll x, ll y ) {
        ll ret = 1;
        for( ll i=2; i*i<=y; i++ ) {
                if( y % i == 0 ) {
                        ll pw1 = 1;
                        ll pw2 = 1;
                        while( x % i == 0 ) {
                                x /= i;
                                pw1 *= i;
                        }
                        while( y % i == 0 ) {
                                y /= i;
                                pw2 *= i;
                        }
                        if( pw2 > pw1 ) {
                                ret *= pw2;
                        }
                }
        }
        if( y != 1 ) ret *= y / x;
        return ret;
}

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%lld %lld %lld", &a, &b, &l );

                ll lcm = __lcm( a, b );

                if( l % lcm ) printf( "Case %d: impossible\n", cs );

                else printf( "Case %d: %lld\n", cs, solve( lcm, l ) );
        }

        return 0;
}
