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

        double r1, r2, r3, ans, a, b, c, s, area;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lf %lf %lf", &r1, &r2, &r3 );

                a = r1 + r2;

                b = r1 + r3;

                c = r2 + r3;

                s = ( a + b + c ) / 2;

                area = sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );

                double angle_a = acos( ( sqr( b ) + sqr( c ) - sqr( a ) ) / ( 2 * b * c ) );

                double angle_b = acos( ( sqr( a ) + sqr( c ) - sqr( b ) ) / ( 2 * a * c ) );

                double angle_c = acos( ( sqr( a ) + sqr( b ) - sqr( c ) ) / ( 2 * a * b ) );

                area -= pi * r3 * r3 * ( angle_a / ( 2 * pi ) );

                area -= pi * r2 * r2 * ( angle_b / ( 2 * pi ) );

                area -= pi * r1 * r1 * ( angle_c / ( 2 * pi ) );

                ans = area;

                printf( "Case %d: %.6f\n", cs, ans );

        }

        return 0;
}