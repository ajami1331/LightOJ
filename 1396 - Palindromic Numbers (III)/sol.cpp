#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 2e5 + 10;
const ll mod = 1000007;

char s[sz], a[sz];
int len, fl, n;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%s", s );

                len = strlen( s );

                if( len == 1 ) {
                        if( s[0] < '9' ) {
                                s[0]++;
                                printf( "Case %d: %s\n", cs, s );
                        }
                        else {
                                printf( "Case %d: 11\n", cs );      
                        }
                }
                else {

                        n = len / 2 + len % 2;

                        for( int i=0; i<n; i++ ) a[i] = s[i];

                        reverse( a, a + n );

                        fl = 0;

                        int f = 0;

                        for( int i=len&1,j=n; i<n && j<len; i++,j++ ) {
                                if( a[i] < s[j] ) {
                                        fl = 1;
                                        break;
                                }
                                else if( a[i] > s[j] ) {
                                        f = 1;
                                        break;
                                }
                        }

                        if( f == 0 ) fl = 1;

                        for( int i=0; i<n; i++ ) {
                                if( fl ) {
                                        a[i] += 1;
                                        fl = 0;
                                        if( a[i] > '9' ) {
                                                a[i] = '0';
                                                fl = 1;
                                        }
                                }
                        }

                        if( fl ) a[n++] = '1', len++;

                        //cerr << s << " " << n << " " << len << "\n";

                        printf( "Case %d: ", cs );

                        for( int i=n-1; i>=0; i-- ) putchar( a[i] );

                        for( int i=n+n-len; i<n; i++ ) putchar( a[i] );

                        putchar( '\n' );

                        }

        }

        return 0;
}