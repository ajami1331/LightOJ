#include <bits/stdc++.h>
using namespace std;

const int mx = 3e4 + 10;
int t, cs, dist, st, n;
bool vis[mx];
vector < pair < int, int > > G[mx];

void dfs( int u, int cost ) {
    vis[u] = 1;
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
//        freopen( "out.txt", V"w+", stdout );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) G[i].clear();
        for( int i=0; i<n-1; i++ ) {
            int x, y, w;
            scanf( "%d %d %d", &x, &y, &w );
            G[x].push_back( { y, w } );
            G[y].push_back( { x, w } );
        }
        memset( vis, 0, sizeof vis );
        dist = 0;
        dfs( 0, 0 );
        dist = 0;
        memset( vis, 0, sizeof vis );
        dfs( st, 0 );
        printf( "Case %d: %d\n", cs, dist );
    }
    return 0;
}
