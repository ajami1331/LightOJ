#include <bits/stdc++.h>
using namespace std;

const int sz = 1005;
const int lim = 1e9 + 1;
const int inf = 1 << 20;
int t, n, m, cs;
int ar[105][105];

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<n; i++ ) {
                        for( int j=0; j<n; j++ ) {
                                ar[i][j] = inf;
                        }
                        ar[i][i] = 0;
                }

                for( int i=0; i<m; i++ ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        ar[x][y] = 1;
                        ar[y][x] = 1;
                }

                for( int via=0; via<n; via++ ) {
                        for( int from=0; from<n; from++ ) {
                                for( int to=0; to<n; to++ ) {
                                        ar[from][to] = min( ar[from][to], ar[from][via] + ar[via][to] );
                                }
                        }
                }

                int ans = 0;

                int s, d;

                scanf( "%d %d", &s, &d );

                for( int i=0; i<n; i++ ) ans = max( ans, ar[i][s] + ar[i][d] );

                printf( "Case %d: %d\n", cs, ans );

//                cerr << "----\n";

        }

        return 0;
}
