#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, fl;
    ll a, b, n;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%lld", &n );
        a = -1, b = -1; fl = 0;
        if( n&1 ) fl = 1;
        else {
            a = 2;
            while( b == -1 ) {
                if( ( n / a ) & 1 ) {
                    b =  n / a;
                } else {
                    a *= 2;
                }
            }
        }
        if( fl ) printf( "Case %d: Impossible\n", cs );
        else printf( "Case %d: %lld %lld\n", cs, b, a );
    }
    return 0;
}
