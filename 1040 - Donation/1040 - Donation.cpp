#include <bits/stdc++.h>
using namespace std;

int tot, mst, ans;
int par[55], cnt[55];

struct ed {
    int x, y, w;
    bool operator < ( const ed &ot ) const {
        return w < ot.w;
    }
} eds [2505];

int find_rep( int u ) {
    return par[u] != u ? par[u] = find_rep( par[u] ) : par[u];
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    int t, n, m;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        m = 0;
        tot = 0;
        mst = 0;
        ans = 0;
        for( int i=0; i<n; i++ ) {
            for( int j=0,w; j<n; j++ ) {
                scanf( "%d", &w );
                if( w ) eds[m++] = { i, j, w };
            }
        }
        sort( eds, eds + m );
        for( int i=0; i<n; i++ ) par[i] = i, cnt[i] = 1;
        for( int i=0,x,y,w; i<m; i++ ) {
            x = eds[i].x;
            y = eds[i].y;
            w = eds[i].w;
            if( ( x = find_rep( x ) ) != ( y = find_rep( y ) ) ) {
                par[x] = par[y];
                cnt[y] += cnt[x];
                mst += w;
            }
            else {
                ans += w;
            }
            tot += w;
        }
        if( cnt[ find_rep( 0 ) ] != n ) ans = -1;
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
