#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, m;
char s[205][205];
int val[205][205];
int lvl[205][205];
int vis[205][205];
int ans, inf;
int dx[] = { +1, -1, +0, +0 };
int dy[] = { +0, +0, +1, -1 };

void prepare() {
        queue < int > Q;
        for( int i=0; i<n; i++ ) {
                for( int j=0; j<m; j++ ) {
                        if( s[i][j] == 'F' ) {
                                Q.push( i );
                                Q.push( j );
                                val[i][j] = 0;
                        }
                }
        }
        int x, y, nx, ny, v;
        while( !Q.empty() ) {
                x = Q.front(); Q.pop();
                y = Q.front(); Q.pop();
                v = val[x][y] + 1;
                for( int i=0; i<4; i++ ) {
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if( nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '#' || val[nx][ny] <= v ) continue;
                        val[nx][ny] = v;
                        Q.push( nx );
                        Q.push( ny );
                }
        }
}

void solve() {
        queue < int > Q;
        for( int i=0; i<n; i++ ) {
                for( int j=0; j<m; j++ ) {
                        if( s[i][j] == 'J' ) {
                                Q.push( i );
                                Q.push( j );
                                lvl[i][j] = 0;
                        }
                }
        }
        int x, y, nx, ny, v;
        while( !Q.empty() ) {
                x = Q.front(); Q.pop();
                y = Q.front(); Q.pop();
                v = lvl[x][y] + 1;
                for( int i=0; i<4; i++ ) {
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if( nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '#' || vis[nx][ny] || val[nx][ny] <= v ) continue;
                        vis[nx][ny] = 1;
                        lvl[nx][ny] = v;
                        Q.push( nx );
                        Q.push( ny );
                }
        }
        ans = inf;
        for( int i=0; i<n; i++ ) { 
                if( vis[i][0] ) ans = min( ans, lvl[i][0] );
                if( vis[i][m - 1] ) ans = min( ans, lvl[i][m - 1] );
        }
        for( int i=0; i<m; i++ ) { 
                if( vis[0][i] ) ans = min( ans, lvl[0][i] );
                if( vis[n - 1][i] ) ans = min( ans, lvl[n - 1][i] );
        }
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<n; i++ ) {
                        scanf( "%s", s[i] );
                }

                memset( val, 31, sizeof val );

                memset( vis, 0, sizeof vis );

                inf = val[0][0];

                prepare();

                solve();

                printf( "Case %d: ", cs );

                if( ans < inf ) printf( "%d\n", ans + 1 );

                else printf( "IMPOSSIBLE\n" );

        }
 
        return 0;
}
