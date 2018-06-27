#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
 
#define sqr( a ) ( ( a ) * ( a ) )
 
int t, n, ans;
int x[705], y[705];
vector < int >  v;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%d", &n );

                ans = 0;

                v.clear();

                for( int i=0; i<n; i++ ) {
                        scanf( "%d %d", &x[i], &y[i] );
                }

                for( int i=0; i<n; i++ ) {
                        for( int j=i; j<n; j++ ) {
                                v.push_back( sqr( x[i] - x[j] ) + sqr( y[i] - y[j] ) );
                        }
                }

                sort( v.begin(), v.end() );

                v.resize( unique( v.begin(), v.end() ) - v.begin() );

                ans = (int)v.size();

                printf( "Case %d: %d\n", cs, ans );
 
        }
 
        return 0;
}
