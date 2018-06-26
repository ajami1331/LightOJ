#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
using ull = unsigned long long;

const int sz = 1e6 + 10;
const ll mod = 1e9 + 7;
#define sqr( a ) ( ( a ) * ( a ) )
const double eps = 1e-6;

int t;
double x, y, c;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
        
                scanf( "%lf %lf %lf", &x, &y, &c );

                double lo = 0, hi = min( x, y ), mid, a, b;

                while( fabs( lo - hi ) > eps ) {
                        mid = ( lo + hi ) / 2;
                        a = acos( mid / x );
                        b = acos( mid / y );
                        a = c / tan( a );
                        b = c / tan( b );
                        if( a + b - mid >= eps ) {
                                hi = mid;
                        }
                        else {
                                lo = mid;
                        }
                }

                printf( "Case %d: %.6f\n", cs, lo );
        }
 
        return 0;
}
