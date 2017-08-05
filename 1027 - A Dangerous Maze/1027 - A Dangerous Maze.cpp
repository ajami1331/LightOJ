#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, n, ans, pos, x;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        ans = 0;
        pos = 0;
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &x );
            pos += x > 0;
            ans += abs( x );
        }
        if( pos == 0 ) {
            printf( "Case %d: inf\n", cs );
        } else {
            long long gcd = __gcd( ans, pos );
            printf( "Case %d: %d/%d\n", cs, ( ans / gcd ), ( pos / gcd ) );
        }
    }
    return 0;
}

