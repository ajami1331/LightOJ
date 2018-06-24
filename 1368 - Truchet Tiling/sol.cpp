#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 205;
const ll mod = 1000007;

const double pi = acos( -1.0 );

int n, m, q;
int cc;
double ans[sz * sz];
double grid[sz][sz];
double sector, box;
int vis[sz][sz];
vector < pair < int, int > > G[sz][sz];

void dfs( int x, int y ) {
        if( vis[x][y] ) return;
        vis[x][y] = cc;
        ans[cc] += grid[x][y];
        for( const auto& it: G[x][y] ) {
                dfs( it.first, it.second );
        }
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<sz; i++ ) {
                        for( int j=0; j<sz; j++ ) {
                                G[i][j].clear();
                        }
                }

                sector = pi / 4.0;

                box = 1.0 - sector;

                memset( grid, 0, sizeof grid );

                memset( ans, 0, sizeof ans );

                for( int i=0; i<n; i++ ) {
                        for( int j=0; j<m; j++ ) {
                                int x, y, h;
                                scanf( "%1d", &h );
                                x = i * 2;
                                y = j * 2;
                                if( h == 0 ) {
                                        grid[x][y] += sector;

                                        grid[x][y + 1] += 0.0;

                                        grid[x][y + 2] += 1.0;

                                        grid[x + 1][y] += 0.0;

                                        grid[x + 1][y + 1] += 1.0 + box + box;

                                        grid[x + 1][y + 2] += 0.0;

                                        grid[x + 2][y] += 0.0;

                                        grid[x + 2][y + 1] += 0.0;

                                        grid[x + 2][y + 2] += sector;

                                        G[x + 1][y + 1].push_back( make_pair( x, y + 2 ) );

                                        G[x][y + 2].push_back( make_pair( x + 1, y + 1 ) );

                                        G[x + 1][y + 1].push_back( make_pair( x + 2, y ) );

                                        G[x + 2][y].push_back( make_pair( x + 1, y + 1 ) );
                                }
                                else {
                                        grid[x][y] += 1.0;

                                        grid[x][y + 1] += 0.0;

                                        grid[x][y + 2] += sector;

                                        grid[x + 1][y] += 0.0;

                                        grid[x + 1][y + 1] += 1.0 + box + box;

                                        grid[x + 1][y + 2] += 0.0;

                                        grid[x + 2][y] += sector;

                                        grid[x + 2][y + 1] += 0.0;

                                        grid[x + 2][y + 2] += 0.0;

                                        G[x + 1][y + 1].push_back( make_pair( x, y ) );

                                        G[x][y].push_back( make_pair( x + 1, y + 1 ) );

                                        G[x + 1][y + 1].push_back( make_pair( x + 2, y + 2 ) );

                                        G[x + 2][y + 2].push_back( make_pair( x + 1, y + 1 ) );
                                }
                        }
                }

                n *= 2;

                m *= 2;

                printf( "Case %d:\n", cs );

                scanf( "%d", &q );

                cc = 0;

                memset( vis, 0, sizeof vis );

                while( q-- ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        if( vis[x][y] == 0 ) {
                                ++cc;
                                dfs( x, y );
                        }
                        printf( "%.10f\n", ans[ vis[x][y] ] );
                }

        }

        return 0;
}