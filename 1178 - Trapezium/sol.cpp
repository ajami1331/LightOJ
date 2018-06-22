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

        int t;

        double a, b, c, d;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lf %lf %lf %lf", &a, &b, &c, &d );

                double s = ( b + d + abs( a - c ) ) / 2.0;

                double area_triangle = sqrt( s * ( s - b ) * ( s - d ) * ( s - abs( a - c ) ) );

                double height = ( area_triangle /  abs( a - c ) )  * 2.0;

                double ans = ( ( a + c ) / 2.0 ) * height;

                printf( "Case %d: %.6f\n", cs, ans );

        }

        return 0;
}