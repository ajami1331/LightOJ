#include <bits/stdc++.h>
using namespace std;

int t, n, k, ans, cs;

int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &k );

                ans = 1;

                for( int i=1; i<=n; i++ ) {
                        ans = ( ans + k ) % i;
                }

                printf( "Case %d: %d\n", cs, ans + 1 );

        }
        return 0;
}
