#include <bits/stdc++.h>
using namespace std;


const int sz = 1e4 +  10;
vector < int > G[sz];
int tim, root, n, m, a, b;
int ap[sz], vis[sz], low[sz], d[sz], par[sz];
map < int, map < int, bool > > mp;
pair < int, int > ed[sz * 3];
set < int > st;

void ap_dfs(int u) {
    tim++;
    int cnt = 0;
    low[u] = tim;
    d[u] = tim;
    vis[u] = 1;
    int v;
    for(int i=0; i<G[u].size(); i++) {
        v = G[u][i];
        if( v == par[u] ) continue;
        if( !vis[v] ) {
            par[u] = v;
            ap_dfs( v );
            low[u] = min( low[u], low[v] );
            /// d[u] < low[v] if bridge is needed
            if( d[u] < low[v] && u != root ) {
                ap[u] = 1;
                mp[u][v] = 1;
                mp[v][u] = 1;
                cerr << u << " " << v << "\n";
            }
            cnt++;
        } else {
            low[u] = min( low[u], d[v] );
        }
        if( u == root && cnt > 1 ) ap[u] = 1;
    }
}

int find_rep( int x ) {
    return par[x] == x ? x : par[x] = find_rep( par[x] );
}

int main() {
    int t, n, m;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        mp.clear();
        for( int i=0,x,y; i<m; i++ ) {
            scanf( "%d %d", &x, &y );
            G[x].push_back( y );
            G[y].push_back( x );
            ed[i].first = x;
            ed[i].second = y;
        }
        for( int i=0; i<=n; i++ ) {
            ap[i] = 0;
            vis[i] = 0;
            low[i] = 0;
            d[i] = 0;
            par[i] = -1;
        }
        ap_dfs( 0 );
        for( int i=0; i<=n; i++ ) par[i] = i;
        for( int i=0,x,y; i<m; i++ ) {
            x = ed[i].first;
            y = ed[i].second;
            if( mp[ x ][ y ] ) continue;
            x = find_rep( x );
            y = find_rep( y );
            if( par[x] != par[y] ) {
                par[x] = par[y];
            }
        }
        st.clear();
        for( int i=1; i<=n; i++ ) st.insert( find_rep( i ) );
        printf( "Case %d: %d\n", cs, st.size() / 2 );
    }
    return 0;
}