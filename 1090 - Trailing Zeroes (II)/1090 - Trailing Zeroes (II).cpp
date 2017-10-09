#include <bits/stdc++.h>
using namespace std;

int func( int n, int p ) {
    int b = p;
    int ret = 0;
    while( b <= n ) {
        ret += n / b;
        b *= p;
    }
    return ret;
}

int main() {
    int t, cs, n, r, p, q, n_r, ans, two, fiv;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d %d", &n, &r, &p, &q );
        two = 0; fiv = 0;
        while( p % 2 == 0 ) p /= 2, two++;
        while( p % 5 == 0 ) p /= 5, fiv++;
        two *= q; fiv *= q;
        n_r = n - r;
        two += func( n, 2 ) - func( r, 2 ) - func( n_r, 2 );
        fiv += func( n, 5 ) - func( r, 5 ) - func( n_r, 5 );
        ans = min( two, fiv );
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}