#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 1e5 + 10;
const int lim = 1e5;
int t, cs;
double l, w;
double lo, hi;

double calc( double x ) {
        return max( l - x - x, 0.0 ) * max( w - x - x, 0.0 ) * x;
}

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%lf %lf", &l, &w );

                lo = 0;

                hi = min( l, w );

                for( int i=0; i<128; i++ ) {
                        double m1 = ( lo + lo + hi ) / 3.0;
                        double m2 = ( lo + hi + hi ) / 3.0;
                        if( calc( m1 ) > calc( m2 ) ) {
                                hi = m2;
                        }
                        else {
                                lo = m1;
                        }
                }

                printf( "Case %d: %.12f\n", cs, calc( lo ) );
        }

        return 0;
}
