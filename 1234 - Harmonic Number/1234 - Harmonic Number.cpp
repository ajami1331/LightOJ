#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;
const double EulerGamma = 0.577215664901532860606512090082;
int t, n, cs;
double ar[sz];

double solve( int n ) {
        if( n < sz ) return ar[n];
        return log( n + 0.5 ) + EulerGamma;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331

        for( int i=1; i<sz; i++ ) {
                ar[ i ] = ar[i - 1] + 1.0 / i;
        }

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                printf( "Case %d: %.8f\n", cs, solve( n ) );

        }

        return 0;
}
