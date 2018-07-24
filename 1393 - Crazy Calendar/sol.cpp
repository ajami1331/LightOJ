#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 3e5 + 10;
const int pr_sz = 1e6 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, cs;
int n, m, _xor, v;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                _xor = 0;

                for( int i=1; i<=n; i++ ) {
                        for( int j=1; j<=m; j++ ) {
                                scanf( "%d", &v );
                                _xor ^= ( ( ( n - i ) + ( m - j ) ) & 1 ) * ( v );
                        }
                }

                printf( "Case %d: %s\n", cs, _xor ? "win" : "lose" );
        }

        return 0;
}