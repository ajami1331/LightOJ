#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e5 + 10;
const ll mod = 1e9 + 7;

int ar[sz], fl, n;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                memset( ar, 0, sizeof ar );

                for( int i=0; i<n; i++ ) {
                        int x;
                        scanf( "%d", &x );
                        ar[x]++;
                }

                fl = 1;

                for( int i=0; i<n; i++ ) {
                        if( ar[i] > 0 ) {
                                ar[i]--;
                        }
                        else if( ar[n - i - 1] > 0 ) {
                                ar[n - i - 1]--;
                        }
                        else {
                                fl = 0;
                                break;
                        }
                }

                printf( "Case %d: %s\n", cs, fl ? "yes" : "no" );

        }

        return 0;
}