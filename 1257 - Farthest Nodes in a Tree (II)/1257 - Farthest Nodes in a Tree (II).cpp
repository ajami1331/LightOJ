#include <bits/stdc++.h>
using namespace std;

const int mx = 3e4 + 10;
bool vis[mx];
int lvl[mx], ans[mx], dist, st;
vector < pair < int, int > > G[mx];

void dfs( int u, int cost ) {
    vis[u] = 1;
    lvl[u] = cost;
    if( cost > dist ) {
        dist = cost;
        st = u;
    }
    for( int i=0; i<G[u].size(); i++ ) {
        if( !vis[ G[u][i].first ] )
            dfs( G[u][i].first, cost + G[u][i].second );
    }
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, n, x, y, z;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) G[i].clear();
        for( int i=0; i<n-1; i++ ) {
            scanf( "%d %d %d", &x, &y, &z );
            G[x].push_back( { y, z } );
            G[y].push_back( { x, z } );
        }
        st = 0, dist = 0;
        memset( ans, 0, sizeof ans );
        memset( vis, 0, sizeof vis );
        dfs( 0, 0 );
        for( int i=0; i<n; i++ ) ans[i] = max( ans[i], lvl[i] );
        memset( vis, 0, sizeof vis );
        dist = 0;
        dfs( st, 0 );
        for( int i=0; i<n; i++ ) ans[i] = max( ans[i], lvl[i] );
        memset( vis, 0, sizeof vis );
        dist = 0;
        dfs( st, 0 );
        printf( "Case %d:\n", cs );
        for( int i=0; i<n; i++ ) printf( "%d\n", max( ans[i], lvl[i] ) );
    }
    return 0;
}
