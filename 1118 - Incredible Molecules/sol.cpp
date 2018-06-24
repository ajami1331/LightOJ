#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e4 + 10;
const ll mod = 1e9 + 7;

#define sqr( a ) a * a

const double pi = acos( -1.0 );
const double eps = 1e-6;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        double x1, y1, r1, x2, y2, r2;

        double ans;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2 );

                ans = 0;

                if( ( r1 + hypot( x1 - x2, y1- y2 ) - r2 <= eps ) || ( r2 + hypot( x1 - x2, y1- y2 ) - r1 <= eps ) ) {
                        ans = sqr( min( r1, r2 ) ) * pi;
                }
                else if( hypot( x1 - x2, y1- y2 ) - r1 - r2 <= eps ) {
                        double d = hypot( x1 - x2, y1 - y2 );
                        double angle_a, angle_b;
                        angle_a = acos( ( sqr( r1 ) + sqr( d ) - sqr( r2 ) ) / ( 2.0 * r1 * d ) ) * 2.0;
                        angle_b = acos( ( sqr( r2 ) + sqr( d ) - sqr( r1 ) ) / ( 2.0 * r2 * d ) ) * 2.0;
                        ans = ( ( angle_a * r1 * r1 ) / 2.0 ) + ( ( angle_b * r2 * r2 ) / 2.0 );
                        ans -= ( ( ( sin( angle_a ) * r1 * r1 ) / 2.0 ) + ( ( sin( angle_b ) * r2 * r2 ) / 2.0 ) );
                }

                printf( "Case %d: %.12lf\n", cs, ans );

        }

        return 0;
}