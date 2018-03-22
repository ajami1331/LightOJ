#include <bits/stdc++.h>
using namespace std;

const int sz = 1005;
const int lim = 1e9 + 1;
const int inf = 1 << 20;
int t, n, c, ans, cs;
int ar[105];

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=1; i<=n; i++ ) {
                        scanf( "%d", &ar[i] );
                }

                ans = 0;

                for( int i=1; i<=n; i++ ) {
                        if( i != ar[i] ) {
                                ans++;
                                for( int j=1; j<=n; j++ ) {
                                        if( i == ar[j] ) {
                                                swap( ar[i], ar[j] );
                                                break;
                                        }
                                }
                        }
                }

                printf( "Case %d: %d\n", cs, ans );

        }

        return 0;
}
