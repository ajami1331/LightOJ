#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct ed {
    int x, y, w;
};

vector < ed > edges;
int par[101], rnk[101];

bool cmp( ed a, ed b ) {
    return a.w > b.w;
}

bool cmpp( ed a, ed b ) {
    return a.w < b.w;
}

int find( int x ) {
    if( x != par[x] ) return par[x] = find( par[x] );
    return x;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "oxt.txt", "w+", stdoxt );
    #endif // LU_SERIOUS
    int t, cs, n, x, y, w, ans;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        edges.clear();
        while( ~scanf( "%d %d %d", &x, &y, &w ) && x+y+w ) {
            edges.push_back( { x, y, w } );
        }
        ans = 0;
        for( int i=0; i<=n; i++ ) par[i] = i;
        for( int i=0; i<=n; i++ ) rnk[i] = 0;
        sort( edges.begin(), edges.end(), cmp );
        for( int i=0; i<edges.size(); i++ ) {
            x = edges[i].x;
            y = edges[i].y;
            w = edges[i].w;
            if( ( x = find( x ) ) != ( y = find( y ) ) ) {
                if( rnk[ x ] < rnk[ y ] ) {
                    par[ x ] = par[ y ];
                } else {
                    rnk[ x ] = max( rnk[ x ], rnk[ y ] + 1 );
                    par[ y ] = par[ x ];
                }
                ans += w;
            }
        }
        for( int i=0; i<=n; i++ ) par[i] = i;
        for( int i=0; i<=n; i++ ) rnk[i] = 0;
        sort( edges.begin(), edges.end(), cmpp );
        for( int i=0; i<edges.size(); i++ ) {
            x = edges[i].x;
            y = edges[i].y;
            w = edges[i].w;
            if( ( x = find( x ) ) != ( y = find( y ) ) ) {
                if( rnk[ x ] < rnk[ y ] ) {
                    par[ x ] = par[ y ];
                } else {
                    rnk[ x ] = max( rnk[ x ], rnk[ y ] + 1 );
                    par[ y ] = par[ x ];
                }
                ans += w;
            }
        }
        if( ans & 1 ) printf( "Case %d: %d/2\n", cs, ans );
        else printf( "Case %d: %d\n", cs, ans / 2 );
    }
    return 0;
}
