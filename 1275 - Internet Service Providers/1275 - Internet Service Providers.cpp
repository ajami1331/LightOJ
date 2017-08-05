#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, c;

ll calc( ll x ) {
    return x * ( c - n * x );
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif /// CLown1331
    int t, cs;
    ll ans, p1, p2;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%lld %lld", &n, &c );
        if( n == 0 ) ans = 0;
        else {
            p1 = ( c / ( 2 * n ) );
            p2 = p1 + 1LL;
            if( calc( p1 ) >= calc( p2 ) ) {
                ans = p1;
            } else {
                ans = p2;
            }
        }
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
