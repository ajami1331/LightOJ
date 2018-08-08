#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
using ll = long long;
const ll mod = 1e9 + 7;
const int sz = 5e4 + 10;
const int inf = 1 << 12;

int t, cs, n;
int dp[sz], ans, mx;
vector < int > G[sz], g[sz], gt[sz], st;
int ar[sz], colr[sz], cc;
int vis[sz];

int rec( int u ) {
        if( ~dp[u] ) return dp[u];
        dp[u] = 0;
        for( const int& v: G[u] ) dp[u] = max( dp[u], rec( v ) );
        return dp[u] += ar[u];
}

void top( int u ) {
        vis[u] = 1;
        for( const int& v: g[u] ) if( vis[v] == 0 ) top( v );
        st.push_back( u );
}

void dfs( int u ) {
        vis[u] = 1;
        colr[u] = cc;
        ar[cc]++;
        for( const int& v: gt[u] ) if( vis[v] == 0 ) dfs( v );
}

void make( int u ) {
        vis[u] = 1;
        for( const int& v: g[u] ) {
                if( vis[v] == 0 ) make( v );
                if( colr[u] != colr[v] ) {
                        G[ colr[u] ].push_back( colr[v] );
                }
        }
}

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<=n; i++ ) G[i].clear(), dp[i] = -1, g[i].clear(), gt[i].clear(), colr[i] = 0, ar[i] = 0;

                for( int i=0; i<n; i++ ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        g[ x ].push_back( y );
                        gt[y].push_back( x );
                }

                cc = 0;

                st.clear();

                memset( vis, 0, sizeof vis );

                for( int i=1; i<=n; i++ ) {
                        if( vis[i] == 0 ) top( i );
                }

                memset( vis, 0, sizeof vis );

                reverse( st.begin(), st.end() );

                for( const int& u: st ) {
                        if( vis[u] == 0 ) {
                                cc++;
                                dfs( u );
                        }
                }

                memset( vis, 0, sizeof vis );

                for( int i=1; i<=n; i++ ) {
                        if( vis[i] == 0 ) make( i );
                }

                mx = 0;

                for( int i=1; i<=n; i++ ) {
                        if( mx < rec( colr[i] ) ) {
                                mx = rec( colr[i] );
                                ans = i;
                        }
                }

                printf( "Case %d: %d\n", cs, ans );
        }

        return 0;
}
