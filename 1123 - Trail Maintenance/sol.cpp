#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1 << 23;
const int pr_sz = 1e6 + 10;
const double eps = 1e-9;
const int mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )

int t, cs, n, m;
int last, ans, ok;
int par[205];

struct edge {
        int x, y, w, u;
} edges[6005];

bool cmp1( const edge& a, const edge& b ) {
        return a.w < b.w;
}

bool cmp2( const edge& a, const edge& b ) {
        return a.u > b.u;
}

void add_edge( int x, int y, int w ) {
        edges[last].x = x;
        edges[last].y = y;
        edges[last].w = w;
        last++;
}

void reset() {
        for( int i=0; i<=n; i++ ) {
                par[i] = i;
        }
}

int find_par( int x ) {
        return par[x] == x ? par[x] : par[x] = find_par( par[x] );
}

void mst() {
        sort( edges, edges + last, cmp1 );
        ans = 0;
        reset();
        for( int i=0; i<last; i++ ) {
                int x = find_par( edges[i].x );
                int y = find_par( edges[i].y );
                int w = edges[i].w;
                edges[i].u = ( x != y );
                if( x != y ) {
                        par[x] = par[y];
                        ans += w;
                }
        }
        sort( edges, edges + last, cmp2 );
        int h = 1;
        for( int i=0; i<last; i++ ) h += edges[i].u;
        last = h;
        if( last != n ) ans = -1;
}

int check() {
        reset();
        for( int i=0; i<last; i++ ) {
                int x = find_par( edges[i].x );
                int y = find_par( edges[i].y );
                if( x != y ) {
                        par[x] = par[y];
                }
        }
        int root = find_par( 1 );
        for( int i=2; i<=n; i++ ) {
                if( find_par( i ) != root ) return 0;
        }
        return 1;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                printf( "Case %d:\n", cs );

                ans = -1;

                ok = 0;

                last = 0;

                while( m-- ) {
                        int x, y, w;
                        scanf( "%d %d %d", &x, &y, &w );
                        add_edge( x, y, w );
                        if( !ok ) ok = check();
                        if( ok ) mst();
                        printf( "%d\n", ans );
                }

        }

        return 0;
}