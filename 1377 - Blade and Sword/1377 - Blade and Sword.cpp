#include <bits/stdc++.h>
using namespace std;

vector < pair < int, int > > tele;
int dirx[] = { +0, +0, +1, -1 };
int diry[] = { +1, -1, +0, +0 };
char str[201][201];
int lvl[201][201];
int vis[201][201];
int t, cs, n, m;
int sx, sy, ex, ey;

struct nd{
    int x, y, f;
};

bool bfs() {
    queue < nd > Q;
    nd hand;
    int nx, ny;
    Q.push( { sx, sy, 0 } );
    vis[sx][sy] = cs;
    lvl[sx][sy] = 0;
    while( !Q.empty() ) {
        hand = Q.front();
        Q.pop();
        if( str[hand.x][hand.y] == '*' ) {
            for( int i=0; i<tele.size(); i++ ) {
                nx = tele[i].first;
                ny = tele[i].second;
                if( ( nx == hand.x && ny == hand.y ) || vis[nx][ny] == cs ) continue;
                else {
                    lvl[nx][ny] = lvl[hand.x][hand.y] + 1;
                    vis[nx][ny] = cs ;
                    Q.push( { nx, ny, 1 } );
                }
            }
            if( hand.f ) {
                for( int i=0; i<4; i++ ) {
                    nx = hand.x + dirx[i];
                    ny = hand.y + diry[i];
                    if( nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == cs || str[nx][ny] == '#' ) continue;
                    lvl[nx][ny] = lvl[hand.x][hand.y] + 1;
                    vis[nx][ny] = cs ;
                    Q.push( { nx, ny, 0 } );
                }
            }
        } else {
            for( int i=0; i<4; i++ ) {
                nx = hand.x + dirx[i];
                ny = hand.y + diry[i];
                if( nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == cs || str[nx][ny] == '#' ) continue;
                lvl[nx][ny] = lvl[hand.x][hand.y] + 1;
                vis[nx][ny] = cs ;
                Q.push( { nx, ny, 0 } );
            }
        }
    }
    return vis[ex][ey] == cs;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        tele.clear();
        for( int i=0; i<n; i++ ) {
            scanf( "%s", str[i] );
        }
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<m; j++ ) {
//                cerr << str[i][j] << " \n"[ j==m-1 ];
                if( str[i][j] == '*' ) {
                    tele.push_back( { i, j } );
                }
                if( str[i][j] == 'P' ) {
                    sx = i;
                    sy = j;
                }
                if( str[i][j] == 'D' ) {
                    ex = i;
                    ey = j;
                }
            }
        }
        if( bfs() ) printf( "Case %d: %d\n", cs, lvl[ex][ey] );
        else {
            if( bfs2() ) {
                printf( "Case %d: %d\n", cs, lvl[ex][ey] );
            } else printf( "Case %d: impossible\n", cs );
        }
    }

    return 0;
}
