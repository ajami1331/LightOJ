#include <bits/stdc++.h>
using namespace std;

const int mx = 2e4 + 10;
vector < int > G[mx], gT[mx];
bool vis[mx];
int nodes[mx], in[mx], out[mx];
stack < int > top_sorted;
int n, m, scc;

void dfs_top_sort(int u) {
	vis[u] = true;
	int v;
	for( int i=0; i<G[u].size(); i++ ) {
        v = G[u][i];
		if(!vis[v]) {
			dfs_top_sort( v );
		}
	}
	top_sorted.push( u );
}

void dfs_kosaraju(int u) {
	vis[u] = 1;
	nodes[u] = scc;
	int v;
	for( int i=0; i<gT[u].size(); i++ ) {
        v = gT[u][i];
		if(!vis[v]) {
			dfs_kosaraju( v );
		}
	}
}

void top_sort() {
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			dfs_top_sort(i);
		}
	}
}

void dfs( int u ) {
    vis[u] = 1;
	int v;
	for( int i=0; i<G[u].size(); i++ ) {
        v = G[u][i];
        if( nodes[u] != nodes[v] ) {
            in[ nodes[v] ]++;
            out[ nodes[u] ]++;
        }
		if(!vis[v]) {
			dfs( v );
		}
	}
}

int kosaraju() {
	memset( vis, 0, sizeof vis );
	top_sort();
	int u, a = 0, b = 0;
	scc = 0;
	memset( vis, 0, sizeof vis );
	memset( nodes, 0, sizeof nodes );
	while(!top_sorted.empty()) {
		u = top_sorted.top();
		top_sorted.pop();
		if(!vis[u]) {
            scc++;
			dfs_kosaraju( u );
        }
	}
	memset( vis, 0, sizeof vis );
	memset( in, 0, sizeof in );
	memset( out, 0, sizeof out );
	for( int i=1; i<=n; i++ ) {
        if( !vis[i] ) {
            dfs( i );
        }
	}
	for( int i=1; i<=scc && scc > 1; i++ ) {
        if( !in[i] ) a++;
        if( !out[i] ) b++;
	}
	return max( a, b ) ;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, x, y, w, src;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        for( int i=0; i<=n; i++ ) {
            G[i].clear();
            gT[i].clear();
        }
        while( m-- ) {
            scanf( "%d %d", &x, &y );
            G[x].push_back( y );
            gT[y].push_back( x );
        }
        printf( "Case %d: %d\n", cs, kosaraju() );
    }
    return 0;
}
