#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
 
#define sqr( a ) ( ( a ) * ( a ) )
 
int t, n, l, w, d;

vector < pair < int, int > > ans;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%d %d %d %d", &l, &w, &n, &d );

                ans.clear();

                for( int i=0; i<n; i++ ) {
                        int x, y, k;
                        char u, v;
                        scanf( "%d %d %c%c", &x, &y, &u, &v );
                        x = ( v == 'W' ) ? abs( x - d ) : x + d;
                        k = x / l;
                        x %= l;
                        x = k & 1 ? l - x : x;
                        y = ( u == 'N' ) ? y + d : abs( y - d );
                        k = y / w;
                        y %= w;
                        y = k & 1 ? w - y : y;
                        ans.push_back( make_pair( x, y ) );
                }

                sort( ans.begin(), ans.end() );
 
                printf( "Case %d:\n", cs );

                for( const auto &it: ans ) printf( "%d %d\n", it.first, it.second );
 
        }
 
        return 0;
}
