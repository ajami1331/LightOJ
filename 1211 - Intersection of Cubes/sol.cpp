#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e4 + 10;
const ll mod = 1e9 + 7;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t, x, y, z, a, b, c, n;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                int x1 = 0, x2 = sz, y1 = 0, y2 = sz, z1 = 0, z2 = sz;

                for( int i=0; i<n; i++ ) {
                        scanf( "%d %d %d %d %d %d", &x, &y, &z, &a, &b, &c );
                        x1 = max( x1, x );
                        y1 = max( y1, y );
                        z1 = max( z1, z );
                        x2 = min( x2, a );
                        y2 = min( y2, b );
                        z2 = min( z2, c );
                }

                int ans = max( 0, x2 - x1 ) * max( 0, y2- y1 ) * max( 0, z2 - z1 );

                printf( "Case %d: %d\n", cs, ans );

        }

        return 0;
}