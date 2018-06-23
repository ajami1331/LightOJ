#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e5 + 10;
const ll mod = 1000007;

int ar[sz];
int K, C, n;
ll ans, a, b;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d %d %d", &K, &C, &n, &ar[0] );

                for( int i=1; i<n; i++ ) {
                        ar[i] = ( 1ll * ar[i - 1] * K + C ) % mod;
                }

                sort( ar, ar + n, greater < int > () );

                a = 0; b = 0;

                ans = 0;

                for( int i=0; i<n; i++ ) {
                        b = 1ll * ( i + 1 ) * ar[i];
                        a += ar[i];
                        ans += abs( a - b );
                }

                printf( "Case %d: %lld\n", cs, ans );

        }

        return 0;
}