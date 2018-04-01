#include <bits/stdc++.h>
using namespace std;

vector < pair < int, int > > tele;
int dirx[] = { +0, +0, +1, -1 };
int diry[] = { +1, -1, +0, +0 };
char str[201][201];
int lvl[201][201][2];
int vis[201][201][2];
int t, cs, n, m;
int sx, sy, ex, ey;

struct nd {
        int x, y, f;
};

bool bfs() {
        queue < nd > Q;
        nd hand;
        int nx, ny;
        Q.push( { sx, sy, 0 } );
        vis[sx][sy][0] = cs;
        lvl[sx][sy][0] = 0;
        while( !Q.empty() ) {
                hand = Q.front();
                Q.pop();
                if( hand.x == ex && hand.y == ey ) return true;
                if( str[hand.x][hand.y] == '*' ) {
                        for( int i=0; i<tele.size(); i++ ) {
                                nx = tele[i].first;
                                ny = tele[i].second;
                                if( ( nx == hand.x && ny == hand.y ) || vis[nx][ny][1] == cs )
                                        continue;
                                else {
                                        lvl[nx][ny][1] = lvl[hand.x][hand.y][hand.f] + 1;
                                        vis[nx][ny][1] = cs ;
                                        Q.push( { nx, ny, 1 } );
                                }
                        }
                        tele.clear();                                           ///  shb gulah teleport visited,
                        tele.push_back( { hand.x, hand.y } );                   ///  back asteh parley hoiloh, ar kuno gulah dorkar nai.
                }
                if( str[hand.x][hand.y] != '*' || ( str[hand.x][hand.y] == '*' && hand.f ) ) {
                        for( int i=0; i<4; i++ ) {
                                nx = hand.x + dirx[i];
                                ny = hand.y + diry[i];
                                if( nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny][0] == cs || str[nx][ny] == '#' )
                                        continue;
                                lvl[nx][ny][0] = lvl[hand.x][hand.y][hand.f] + 1;
                                vis[nx][ny][0] = cs ;
                                Q.push( { nx, ny, 0 } );
                        }
                }
        }
        return vis[ex][ey][0] == cs;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {
                scanf( "%d %d", &n, &m );
                tele.clear();
                for( int i=0; i<n; i++ ) {
                        scanf( "%s", str[i] );
                }
                for( int i=0; i<n; i++ ) {
                        for( int j=0; j<m; j++ ) {
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
                if( bfs() )
                        printf( "Case %d: %d\n", cs, lvl[ex][ey][0] );
                else
                        printf( "Case %d: impossible\n", cs );

        }

        return 0;
}
