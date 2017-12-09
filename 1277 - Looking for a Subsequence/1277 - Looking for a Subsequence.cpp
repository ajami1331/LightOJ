#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 10;
int ar[sz], br[sz], cr[sz];
int t, cs, n, q, m, fl, pr;
int tr[sz], lis[sz];
void upd( int x, int v ) {
    for( ; x<sz; x+=(x&-x) ) tr[x] = max( tr[x], v );
}
int qu( int x ) {
    int ret = 0;
    for( ; x>0; x-=(x&-x) ) ret = max( tr[x], ret );
    return ret;
}
int main() {
    scanf( "%d", &t );
    br[0] = INT_MIN;
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &q );
        for( int i=1; i<=n; i++ ) scanf( "%d", &ar[i] ), cr[i] = br[i] = ar[i];
        sort( br, br + 1 + n );
        for( int i=1; i<=n; i++ ) ar[i] = n - ( lower_bound( br, br + 1 + n, ar[i] ) - br ) + 1;
        memset( tr, 0, sizeof tr );
        reverse( ar + 1, ar + 1 + n );
        for( int i=1; i<=n; i++ ) {
            lis[i] = qu( ar[i] - 1 ) + 1;
            upd( ar[i], lis[i] );
        }
        reverse( ar + 1, ar + 1 + n );
        reverse( lis + 1, lis + 1 + n );
        printf( "Case %d:\n", cs );
        while( q-- ) {
            scanf( "%d", &m );
            fl = 0; pr = INT_MAX;
            for( int i=1; i<=n && m>0; i++ ) {
                if( lis[i] >= m && ar[i] < pr ) {
                    --m;
                    pr = ar[i];
                    if( fl ) printf( " " );
                    printf( "%d", cr[i] );
                    fl = 1;
                }
            }
            if( fl ) printf( "\n" );
            else printf( "Impossible\n" );
        }
    }
    return 0;
}