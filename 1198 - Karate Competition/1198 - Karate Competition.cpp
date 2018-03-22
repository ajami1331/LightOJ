#include <bits/stdc++.h>
using namespace std;

const int mod = 1000007;
const int INF = 1e9;
const int sz = 3e5 + 10;

int t, cs, n;
int match[56];
int usd[56];
int a[56];
int b[56];

int solve() {
        int ret = 0;
        sort( a, a + n, less < int > () );
        sort( b, b + n, greater < int > () );
        memset( match, -1, sizeof match );
        memset( usd, -1, sizeof usd );
        for( int i=0; i<n; i++ ) {
                for( int j=0; j<n; j++ ) {
                        if( match[i] == -1 && usd[j] == -1 && b[i] < a[j] ) {
                                match[i] = j;
                                usd[j] = i;
                                ret += 2;
                        }
                }
        }
        for( int i=0; i<n; i++ ) {
                for( int j=0; j<n; j++ ) {
                        if( match[i] == -1 && usd[j] == -1 && b[i] == a[j] ) {
                                match[i] = j;
                                usd[j] = i;
                                ret += 1;
                        }
                }
        }
        return ret;
}

int main() {
        #ifdef CLown1331
                freopen("in.txt", "r", stdin);
        #endif ///CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<n; i++ ) scanf( "%d", &a[i] );

                for( int i=0; i<n; i++ ) scanf( "%d", &b[i] );

                int ans = solve();

                printf( "Case %d: %d\n", cs, ans );
        }

        return 0;
}
