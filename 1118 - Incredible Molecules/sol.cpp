#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e4 + 10;
const ll mod = 1e9 + 7;

#define sqr( a ) a * a

const double pi = acos( -1.0 );

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        double r1, r2, h, p, x, r3, ans;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lf %lf %lf %lf", &r1, &r2, &h, &p );

                x = ( h * r2 ) / ( r1 - r2 );

                r3 = ( p * ( r1 - r2 ) + ( h * r2 ) ) / h;
                
                ans = ( pi * r3 * r3 * ( p + x ) ) / 3.0;

                ans -= ( pi * r2 * r2 * ( x ) ) / 3.0;

                printf( "Case %d: %.6f\n", cs, ans );

        }

        return 0;
}