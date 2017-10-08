#include <bits/stdc++.h>
using namespace std;

char str[12][12];
int dis[12][12];
int lvl[12][12];
int n, m;

const int dxk[] = { -2, -2, -1, -1, +1, +1, +2, +2 };
const int dyk[] = { +1, -1, +2, -2, +2, -2, +1, -1 };

void bfs( int x, int y ) {
    queue < pair < int, int > > Q;
    Q.push( make_pair( x, y ) );
    lvl[x][y] = 0;
    int nx, ny;
    while( !Q.empty() ) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for( int i=0; i<8; i++ ) {
            nx = x + dxk[i];
            ny = y + dyk[i];
            if( nx < 0 || ny < 0 || nx >= n || ny >= m || lvl[nx][ny] != -1 ) continue;
            lvl[nx][ny] = lvl[x][y] + 1;
            Q.push( make_pair( nx, ny ) );
        }
    }
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    int t, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        ans = 1 << 25;
        for( int i=0; i<n; i++ ) {
            scanf( "%s", str[i] );
        }
        memset( dis, 0, sizeof dis );
        for( int i=0; i<n; i++ ) {
            for( int j=0,h=0,kt; j<m; j++ ) {
                memset( lvl, -1, sizeof lvl );
                bfs( i, j );
                lvl[i][j] = 0;
                h = 0;
                kt = 1;
                for( int k=0; k<n; k++  ) {
                    for( int l=0; l<m; l++ ) {
                        if( str[k][l] == '.' ) continue;
                        if( lvl[k][l] < 0 ) {
                            kt = 0;
                            break;
                        }
                        h += lvl[k][l] / ( str[k][l] - '0' );
                        h += lvl[k][l] % ( str[k][l] - '0' ) ? 1 : 0;
                    }
                }
                if( kt ) ans = min( h, ans );
            }
        }
        if( ans == ( 1 << 25 ) ) ans = -1;
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
