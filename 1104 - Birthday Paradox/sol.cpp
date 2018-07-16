#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e4 + 10;
const int pr_sz = 1e6 + 10;
const double eps = 1e-9;
const int mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n;
int ans;
double prob;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                ans = 1;

                prob = 1.0;

                for( ; (1.0-prob)<0.5; ans++ ) {
                        prob *= ( n - ans ) / ( 1.0 * n );
                }

                printf( "Case %d: %d\n", cs, ans - 1 );

        }

        return 0;
}
