#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 3e5 + 10;
const ll mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )

int t, cs;
ll n, ans;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%lld", &n );

                ans = n;

                for( ll i=1; i*i<=n; i++ ) {
                        ans--;
                        if( 2ll * i * i <= n ) ans--;
                }

                printf( "Case %d: %lld\n", cs, ans );

        }

        return 0;
}