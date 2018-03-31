#include <bits/stdc++.h>
using namespace std;


int t, cs, n, m, e;

int fl[505];
int match[505];
int g[505][505];

bool bpm( int u ) {
        for( int v=0; v<e; v++ ) {
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
        for( int i=0; i<e; i++ ) {
                memset( fl, 0, sizeof fl );
                if( bpm( i ) ) {
                        ret++;
                }
        }
        return ret;
}

char a[505], b[505];
int u[505], v[505];

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d %d", &n, &m, &e );

                for( int i=0; i<e; i++ ) {
                        getchar();
                        scanf( "%c%d %c%d", &a[i], &u[i], &b[i], &v[i] );
                }

                memset( g, 0, sizeof g );

                for( int i=0; i<e; i++ ) {
                        for( int j=0; j<e; j++ ) {
                                if( a[i] == b[j] && ( u[i] == v[j] || v[i] == u[j] ) ) g[i][j] = 1;
                        }
                }

                printf( "Case %d: %d\n", cs, e - max_match() / 2 );

        }
        return 0;
}
