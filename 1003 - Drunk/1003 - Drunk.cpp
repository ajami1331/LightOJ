#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 10;
map < string, int > mp;
vector < int > G[mx], tops;
bool vis[mx], bg[mx];

bool dfs( int u ) {
    bool ret = true;
    if( !vis[u] ) {
        vis[u] = 1;
        bg[u] = 1;
        int v;
        for( int i=0; i<G[u].size(); i++ ) {
            v = G[u][i];
            if( !vis[v] ) {
                ret &= dfs( v );
            }
            if( bg[v] ) return false;
        }
    }
    bg[u] = false;
    return true;
}

bool dag( int n) {
    memset( vis, 0, sizeof vis );
    memset( bg, 0, sizeof bg );
    bool ret = true;
    for( int i=1; i<=n; i++ ) {
        if( !vis[i] ) {
            ret &= dfs( i );
        }
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, m, k;
    string x, y;
    cin >> t;
    for( int cs=1; cs<=t; cs++ ) {
        cin >> m;
        k = 0;
        mp.clear();
        for( int i=0; i<mx; i++ ) G[i].clear();
        while( m-- ) {
            cin >> x >> y;
            if( !mp[x] ) {
                mp[x] = ++k;
            }
            if( !mp[y] ) {
                mp[y] = ++k;
            }
            G[ mp[x] ].push_back( mp[y] );
        }
        if( dag( k ) ) {
            printf( "Case %d: Yes\n", cs );
        } else {
            printf( "Case %d: No\n", cs );
        }
    }
    return 0;
}

