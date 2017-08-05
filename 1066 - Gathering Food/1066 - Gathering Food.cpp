#include <bits/stdc++.h>
using namespace std;

char mp[12][12];
int vis[12][12];
int _time[12][12];
int dx[] = { +1, -1, +0, +0 };
int dy[] = { +0, +0, +1, -1 };
int fl, n;
char mx;

int bfs( int x, int y, char c ) {
    if( c == mx ) return 0;
    memset( vis, 0, sizeof vis );
    memset( _time, 0, sizeof _time );
    queue < pair < int, int > > Q;
    Q.push( { x, y } );
    vis[x][y] = 1;
    _time[x][y] = 0;
    int nx, ny;
    while( !Q.empty() ) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for( int i=0; i<4; i++ ) {
            nx = x + dx[i];
            ny = y + dy[i];
            if( nx < 0 || ny < 0 || nx >= n || ny >= n ) continue;
            if( mp[nx][ny] == c + 1 ) {
                int h = _time[x][y] + 1;
                return bfs( nx, ny, c + 1 ) + h;
            }
            if( !vis[nx][ny] && ( mp[nx][ny] == '.' || ( isalpha( mp[nx][ny] ) && mp[nx][ny] <= c ) ) ) {
                vis[nx][ny] = 1;
                _time[nx][ny] = _time[x][y] + 1;
                Q.push( { nx, ny } );
            }
        }
    }

    fl = 0;

    return 0;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    int t, cs, x, y, ret;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) {
            scanf( "%s", mp[i] );
        }
        mx = 0;
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                if( mp[i][j] == 'A' ) {
                    x = i;
                    y = j;
                } else if( isalpha( mp[i][j] ) ) {
                    mx = max( mp[i][j], mx );
                }
            }
        }
        fl = 1;
        if( mx ) ret = bfs( x, y, 'A' );
        else ret = 0;
        if( fl ) printf( "Case %d: %d\n", cs, ret );
        else printf( "Case %d: Impossible\n", cs );
    }
    return 0;
}
