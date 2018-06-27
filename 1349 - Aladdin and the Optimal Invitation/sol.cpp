#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 5e4 + 10;
 
#define sqr( a ) ( ( a ) * ( a ) )
 
int t, n, m, q, ax, ay;
int row[sz], col[sz], total, half;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d %d", &n, &m, &q );

                fill( row, row + 2 + n, 0 );

                fill( col, col + 2 + m, 0 );

                total = 0;

                while( q-- ) {
                        int x, y, w;
                        scanf( "%d %d %d", &x, &y, &w );
                        row[x] += w;
                        col[y] += w;
                        total += w;
                }

                half = ceil( total / 2.0 );

                for( int i=1; i<=n; i++ ) {
                        row[i] += row[i - 1];
                        if( row[i] >= half ) {
                                ax = i;
                                break;
                        }
                }

                for( int i=1; i<=m; i++ ) {
                        col[i] += col[i - 1];
                        if( col[i] >= half ) {
                                ay = i;
                                break;
                        }
                }

                printf( "Case %d: %d %d\n", cs, ax, ay );
 
        }
 
        return 0;
}
