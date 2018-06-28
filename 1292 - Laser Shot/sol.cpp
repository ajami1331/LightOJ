#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1005;
const int mod = 1000000007;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, ans, cal;
int x[sz], y[sz];
map < pair < int, int >, int > mp;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<n; i++ ) {
                        scanf( "%d %d", &x[i], &y[i] );
                }

                ans = 0;

                for( int i=0; i<n; i++ ) {
                        mp.clear();
                        for( int j=i+1; j<n; j++ ) {
                                int xx = x[i] - x[j];
                                int yy = y[i] - y[j];
                                int g = __gcd( xx, yy );
                                xx /= g;
                                yy /= g;
                                mp[ make_pair( xx, yy ) ]++;
                                ans = max( ans, mp[ make_pair( xx, yy ) ] );
                        }
                }

                printf( "Case %d: %d\n", cs, ans + 1 );
 
        }
 
        return 0;
}
