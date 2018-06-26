#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
 
#define sqr( a ) ( ( a ) * ( a ) )
 
int t, n, lo, hi, mid;
int ar[sz];

int check( int x ) {
        for( int i=1; i<=n; i++ ) {
                if( ar[i] - ar[i - 1] > x ) return 0;
                if( ar[i] - ar[i - 1] == x ) --x;
        }
        return 1;
}
 
int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%d", &n );

                for( int i=1; i<=n; i++ ) scanf( "%d", &ar[i] );

                lo = 1, hi = 1e9;

                while( hi - lo > 4 ) {
                        mid = ( lo + hi ) / 2;
                        if( check( mid ) ) {
                                hi = mid;
                        }
                        else {
                                lo = mid;
                        }
                }

                for( ; lo<=hi; lo++ ) {
                        if( check( lo ) ) break;
                }
 
                printf( "Case %d: %d\n", cs, lo );
 
        }
 
        return 0;
}
