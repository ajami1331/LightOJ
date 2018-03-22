#include <bits/stdc++.h>
using namespace std;

const int sz = 1005;
const int lim = 1e9 + 1;
const int inf = 1 << 20;
int t, n, m, q, cs;
int vis[505][505];
int ans[505 * 505];
char s[505][505];

void dfs( int x, int y, int c ) {
        if( x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == '#' ) return;
        vis[x][y] = c;
        ans[c] += s[x][y] == 'C';
        dfs( x + 1, y, c );
        dfs( x - 1, y, c );
        dfs( x, y + 1, c );
        dfs( x, y - 1, c );
}

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d %d", &n, &m, &q );

                for( int i=0; i<n; i++ ) scanf( "%s", s[i] );

                memset( vis, 0, sizeof vis );

                memset( ans, 0, sizeof ans );

                for( int i=0,c=0; i<n; i++ ) {
                        for( int j=0; j<m; j++ ) {
                                if( s[i][j] != '#' && vis[i][j] == 0 ) dfs( i, j, ++c );
                        }
                }

                printf( "Case %d:\n", cs );

                while( q-- ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        printf( "%d\n", ans[ vis[x - 1][y - 1] ] );
                }

        }

        return 0;
}
