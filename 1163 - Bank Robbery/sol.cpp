#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
using ull = unsigned long long;

const int sz = 1e5 + 10;
const ll mod = 1000;
#define sqr( a ) ( ( a ) * ( a ) )
 
int t;
ull n, lo, hi, mid;

ull f( ull x ) {
        return x - ( x / 10 );
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%llu", &n );
 
                lo = 0, hi = 1ll << 62;

                while( hi - lo > 4 ) {
                        mid = ( lo + hi ) / 2;
                        if( f( mid ) >= n ) {
                                hi = mid;
                        }
                        else {
                                lo = mid;
                        }
                }

                for( ; lo<=hi; lo++ ) {
                        if( f( lo ) == n ) break;
                }

                printf( "Case %d: %llu", cs, lo );

                if( f( lo + 1 ) == n ) printf( " %llu\n", lo + 1 );
                else printf( "\n" );
        }
 
        return 0;
}
