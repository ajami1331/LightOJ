#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e4 + 10;
const ll mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )

int t, cs, n, m, a, ans, cnt;

struct edge {
        int x, y, c;
        bool operator < ( const edge& rhs ) const {
                return c < rhs.c;
        }
} e[sz * 10];

int par[sz];

void reset() {
        for( int i=0; i<sz; i++ ) par[i] = i;
}

int find( int x ) {
        return x == par[x] ? par[x] : par[x] = find( par[x] );
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d %d", &n, &m, &a );

                for( int i=0; i<m; i++ ) {
                        scanf( "%d %d %d", &e[i].x, &e[i].y, &e[i].c );
                }

                sort( e, e + m );

                ans = 0; cnt = 0;

                reset();

                for( int i=0; i<m; i++ ) {
                        int x = find( e[i].x );
                        int y = find( e[i].y );
                        int c = e[i].c;
                        if( x != y && c < a ) {
                                par[x] = par[y];
                                ans += c;
                        }
                }

                for( int i=1; i<=n; i++ ) if( find( i ) == i ) ans += a, cnt++;

                printf( "Case %d: %d %d\n", cs, ans, cnt );

        }

        return 0;
}