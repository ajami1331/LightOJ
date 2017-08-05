#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int sz = 1e5 + 10;
ll ar[sz], ans;

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif /// CLown1331
    int t, cs, n, q, ty, x;
    ll v;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &q );
        for( int i=0; i<n; i++ ) scanf( "%lld", &ar[i] );
        printf( "Case %d:\n", cs );
        ans = 0LL;
        for( int i=0; i<n; i++ ) {
            ans -= ar[i] * i;
            ans += ar[i] * ( n - i - 1 );
        }
        while( q-- ) {
            scanf( "%d", &ty );
            if( ty ) {
                printf( "%lld\n", ans );
            } else {
                scanf( "%d %lld", &x, &v );
                ans += ar[x] * x;
                ans -= ar[x] * ( n - x - 1 );
                ar[x] = v;
                ans -= ar[x] * x;
                ans += ar[x] * ( n - x - 1 );
            }
        }
    }
    return 0;
}
