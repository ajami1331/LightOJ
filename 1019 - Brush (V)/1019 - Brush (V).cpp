#include <bits/stdc++.h>
using namespace std;

const int inf = 1e6;
int ar[102][102];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, n, m, x, y, w;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        for( int i=1; i<=n; i++ ) {
            for( int j=1; j<=n; j++ ) {
                ar[i][j] = inf;
            }
            ar[i][i] = 0;
        }
        while( m-- ) {
            scanf( "%d %d %d", &x, &y, &w );
            ar[x][y] = min( ar[x][y] , w );
            ar[y][x] = min( ar[y][x] , w );
        }
        for( int via=1; via<=n; via++ ) {
            for( int from=1; from<=n; from++ ) {
                for( int to=1; to<=n; to++ ) {
                    ar[ from ][ to ] = min( ar[ from ][ via ] + ar[ via ][ to ], ar[ from ][ to ] );
                }
            }
        }
        if( ar[1][n] >= inf ) printf( "Case %d: Impossible\n", cs );
        else printf( "Case %d: %d\n", cs, ar[1][n] );
    }
    return 0;
}
