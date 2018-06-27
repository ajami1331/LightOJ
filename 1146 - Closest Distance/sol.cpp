#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 5e4 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )
 
int t;
double ax, ay, bx, by, cx, cy, dx, dy, dx1, dy1, dx2, dy2, ans;

double f( double x ) {
        double x1 = ax + x * dx1;
        double y1 = ay + x * dy1;
        double x2 = cx + x * dx2;
        double y2 = cy + x * dy2;
        return sqrt( sqr( x1 - x2 ) + sqr( y1 - y2 ) );
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy );

                dx1 = bx - ax;

                dx2 = dx - cx;

                dy1 = by - ay;

                dy2 = dy - cy;

                double lo = 0.0, hi = 1.0, m1, m2;

                while( fabs( lo - hi ) > eps ) {
                        m1 = ( lo + lo + hi ) / 3.0;
                        m2 = ( lo + hi + hi ) / 3.0;
                        if( f( m1 ) > f( m2 ) ) {
                                lo = m1;
                        }
                        else {
                                hi = m2;
                        }
                }

                ans = f( lo );

                printf( "Case %d: %.6f\n", cs, ans );
 
        }
 
        return 0;
}
