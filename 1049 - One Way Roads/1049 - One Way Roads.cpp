#include <bits/stdc++.h>
using namespace std;

int vis[105], sum, df, n;
vector < pair < int, int > > G[105];

int dfs( int u, int p = 0 ) {
    if( !u ) return u;
    vis[u] = 1;
    int v;
    for( int i=0; i<G[u].size(); i++ ) {
        v = G[u][i].first;
        if( v != p ) {
            return dfs( v, u ) + G[u][i].second;
        }
    }
    return 0;
}

int main() {
    int t;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        sum = 0;
        for( int i=0; i<n; i++ ) G[i].clear();
        for( int i=0; i<n; i++ ) {
            int a, b, c;
            scanf( "%d %d %d", &a, &b, &c );
            G[a - 1].push_back( make_pair( b - 1, 0 ) );
            G[b - 1].push_back( make_pair( a - 1, c ) );
        }
        sum = dfs( G[0][0].first ) + G[0][0].second;
        df = dfs( G[0][1].first ) + G[0][1].second;
        printf( "Case %d: %d\n", cs, min( sum, df ) );
    }
    return 0;
}