/**
*
*       Beware of duplicate points, :s koto wa khaialam :s
        1
        4
        0 0
        0 0
        0 0
        0 0
*
**/
#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
#define sq(x) ((x)*(x))
#define isRight(r,a,b) ((b.y-r.y)*(a.x-r.x)<(b.x-r.x)*(a.y-r.y))
#define ABS(a,r) (sqrt(sq(a.x-r.x)+sq(a.y-r.y)))
#define angle(r,a,b) ((180.0*(acos(dot(r,a,b)/(ABS(a,r)*ABS(b,r)))))/PI)
#define dot(r,a,b) ((a.x-r.x)*(b.x-r.x)+(a.y-r.y)*(b.y-r.y))

typedef long long ll;

const int sz = 1e5 + 10;

struct Point {
        ll x, y;
        bool operator < ( const Point &ot ) const {
                if( y == ot.y ) {
                        return x < ot.x;
                }
                return y < ot.y;
        }
};

Point points[sz], hull[sz], pivot;
int hullIndex;

ll sqrDist( Point a, Point b ) {
        ll dx = a.x - b.x, dy = a.y - b.y;
        return dx * dx + dy * dy;
}

int ccw( Point a, Point b, Point c ) {
        ll area = ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
        if( area > 0 ) {
                return -1;
        } else if( area < 0 ) {
                return 1;
        }
        return 0;
}

bool cmp( const Point& a, const Point& b ) {
        int order = ccw( pivot, a, b );
        if( !order ) {
                return sqrDist( pivot, a ) < sqrDist( pivot, b );
        }
        return ( order == -1 );
}

bool cmpPos( const Point& a, const Point& b ) {
        return a.x == b.x && a.y == b.y;
}

bool grahamScan( int n ) {
        hullIndex = 0;
        if( n < 3 )
                return false;
        int minY = 0;
        for( int i=1; i<n; i++ ) {
                if( points[i] < points[minY] ) {
                        minY = i;
                }
        }
        swap( points[0], points[minY] );
        pivot = points[0];
        sort( points + 1, points + n, cmp );
        hull[0] = points[0];
        hull[1] = points[1];
        hull[2] = points[2];
        hullIndex = 3;
        for( int i=3; i<n; i++ ) {
                while( hullIndex >= 2 && ccw( hull[hullIndex - 2], hull[hullIndex - 1], points[ i ] ) > -1 ) {
                        hullIndex--;
                }
                hull[ hullIndex++ ] = points[i];
        }
        return hullIndex >= 3;
}

double solve( int n ) {
        sort( points, points + n );
        n = unique( points, points + n, cmpPos ) - points;
        grahamScan( n );
        double ret = 361.0;
        if( hullIndex < 3 ) return 0;
        for( int i=0; i<hullIndex; i++ ) {
                ret = min( ret, angle( hull[ ( i + 1 ) % hullIndex ], hull[ i ], hull[ ( i + 2 ) % hullIndex ] ) );
        }
        return ret;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331
        int n, t;
        scanf( "%d", &t );
        for( int cs=1; cs<=t; cs++ ) {
                scanf( "%d", &n );
                for( int i=0; i<n; i++ ) {
                        scanf( "%lld %lld", &points[i].x, &points[i].y );
                }
                printf( "Case %d: %.6f\n", cs, solve( n ) );
        }
        return 0;
}

