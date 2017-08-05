#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 10;
vector < int > G[mx], top;
bool vis[mx];

void dfs_top( int u ) {
    vis[u] = 1;
    int v;
    for( int i=0; i<G[u].size(); i++ ) {
        v = G[u][i];
        if( !vis[v] ) dfs_top( v );
    }
    top.push_back( u );
}

void dfs( int u ) {
    vis[u] = 1;
    int v;
    for( int i=0; i<G[u].size(); i++ ) {
        v = G[u][i];
        if( !vis[v] ) dfs( v );
    }
}

int top_sort( int n ) {
    memset( vis, 0, sizeof vis );
    int ret = 0;
    top.clear();
    for( int i=0; i<n; i++ ) {
        if( !vis[i] ) {
            dfs_top( i );
        }
    }
    memset( vis, 0, sizeof vis );
    reverse( top.begin(), top.end() );
    for( int i=0; i<n; i++ ) {
        if( !vis[ top[i] ] ) {
            dfs( top[i] );
            ret++;
        }
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, n, m, x, y;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        for( int i=0; i<n; i++ ) G[i].clear();
        while( m-- ) {
            cin >> x >> y;
            --x, --y;
            G[ x ].push_back( y );
        }
        printf( "Case %d: %d\n", cs, top_sort( n )  );
    }
    return 0;
}
