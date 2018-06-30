#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t;
ll a, b, n, ans, i;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lld", &n );

                ans = n;

                if( n != 1 ) ans += 1;

                b = n;

                for( i=2; i*i<=n; i++ ) {
                        a = n / i;
                        ans += a;
                        if( n / i != i ) ans += i;
                        ans += ( b - a - 1 ) * ( i - 1 );
                        b = a;
                }

                for( ; i<b; i++ ) ans += n / i;

                printf( "Case %d: %lld\n", cs, ans );

        }
 
        return 0;
}
