#include <bits/stdc++.h>
using namespace std;


int t, cs, n, m;
int fl[1005];
int match[1005];
int g[1005][1005];

bool bpm( int u ) {
        for( int v=0; v<n; v++ ) {
                if( g[u][v] && !fl[v] ) {
                        fl[v] = true;
                        if( match[v] == -1 || bpm( match[v] ) ) {
                                match[v] = u;
                                return true;
                        }
                }
        }
        return false;
}

int max_match() {
        memset( match, -1, sizeof match );
        int ret = 0;
        for( int i=0; i<n; i++ ) {
                memset( fl, 0, sizeof fl );
                if( bpm( i ) ) {
                        ret++;
                }
        }
        return ret;
}


int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                memset( g, 0, sizeof g );

                scanf( "%d %d", &n, &m );

                while( m-- ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        --x, --y;
                        g[x][y] = 1;
                        g[y][x] = 1;
                }

                printf( "Case %d: %d\n", cs, n - max_match() / 2 );

        }
        return 0;
}
