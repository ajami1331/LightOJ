#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;

double sqr( double x ) {
    return x * x;
}

double dist( double x1, double y1, double x2, double y2 ) {
    return sqrt( sqr( x1-x2 ) + sqr( y2-y1 ) );
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t;
    double ax, ay, bx, by, ox, oy;
    double angle, ans, ab, oa, ob;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%lf %lf %lf %lf %lf %lf", &ox, &oy, &ax, &ay, &bx, &by );
        ab = dist( ax, ay, bx, by );
        oa = dist( ax, ay, ox, oy );
        ob = dist( bx, by, ox, oy );
        angle = acos( ( sqr( oa ) + sqr( ob ) - sqr( ab ) ) / ( 2 * oa * ob ) );
        ans = oa * angle;
        printf( "Case %d: %.12f\n", cs, ans );
    }
    return 0;
}
