#include <bits/stdc++.h>
using namespace std;

int dirx[] = { 0,  0, 0,  0, 1, -1 };
int diry[] = { 0,  0, 1, -1, 0,  0 };
int dirz[] = { 1, -1, 0,  0, 0,  0 };
bool vis[26][26][26];
int lvl[26][26][26];
string st, en, a, b, c;
int sx, sy, sz, ex, ey, ez;

struct nd {
    int x, y, z;
};

bool bfs() {
    int nx, ny, nz;
    nd han;
    queue < nd > Q;
    Q.push( { sx, sy, sz } );
    vis[sx][sy][sz] = 1;
    lvl[sx][sy][sz] = 0;
    while( !Q.empty() ) {
        han = Q.front();
        Q.pop();
        for( int i=0; i<6; i++ ) {
            nx = han.x + dirx[i];
            ny = han.y + diry[i];
            nz = han.z + dirz[i];
            if( nx < 0 ) nx = 25;
            if( ny < 0 ) ny = 25;
            if( nz < 0 ) nz = 25;
            if( nx > 25 ) nx = 0;
            if( ny > 25 ) ny = 0;
            if( nz > 25 ) nz = 0;
            if( nx < 0 || ny < 0 || nz < 0 || nx > 25 || ny > 25 || nz > 25 || vis[nx][ny][nz] ) continue;
            vis[nx][ny][nz] = 1;
            lvl[nx][ny][nz] = lvl[han.x][han.y][han.z] + 1;
            Q.push( { nx, ny, nz } );
        }
    }
    return vis[ex][ey][ez];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, n;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        memset( lvl, 0, sizeof lvl );
        memset( vis, 0, sizeof vis );
        cin >> st >> en;
        sx = st[0] - 'a';
        sy = st[1] - 'a';
        sz = st[2] - 'a';
        ex = en[0] - 'a';
        ey = en[1] - 'a';
        ez = en[2] - 'a';
        scanf( "%d", &n );
        while( n-- ) {
            cin >> a >> b >> c;
            for( int i=0; i<a.size(); i++ ) {
                for( int j=0; j<b.size(); j++ ) {
                    for( int k=0; k<c.size(); k++ ) {
                        vis[a[i]-'a'][b[j]-'a'][c[k]-'a'] = 1;
                    }
                }
            }
        }
        printf( "Case %d: ", cs );
        if( vis[sx][sy][sz] or vis[ex][ey][ez] ) printf( "-1\n" );
        else if( !bfs() )  printf( "-1\n" );
        else printf( "%d\n", lvl[ex][ey][ez] );
    }
    return 0;
}
