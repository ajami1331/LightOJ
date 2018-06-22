#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e6 + 10;
const ll mod = 1e9 + 7;

int ar[sz], br[sz], cr[sz], fl, n;
int tr[sz], m, ans;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                m = 0;

                memset( tr, 0, sizeof tr );

                for( int i=0; i<n; i++ ) {
                        scanf( "%d %d", &ar[i], &br[i] );
                        cr[m++] = ar[i];
                        cr[m++] = br[i];
                }

                sort( cr, cr + m );

                for( int i=0; i<n; i++ ) {
                        int x, y;
                        x = ( lower_bound( cr, cr + m, ar[i] ) - cr ) + 1;
                        y = ( lower_bound( cr, cr + m, br[i] ) - cr ) + 1;
                        tr[x]++;
                        tr[y + 1]--;
                }

                ans = 0;

                for( int i=1; i<=m; i++ ) {
                        tr[i] += tr[i - 1];
                        ans = max( ans, tr[i] );
                }

                printf( "Case %d: %d\n", cs, ans );

        }

        return 0;
}