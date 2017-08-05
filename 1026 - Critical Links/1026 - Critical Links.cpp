#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 10;
vector < int > G[mx];
vector < pair < int, int > > bridges;
int low[mx], d[mx], vis[mx];
int tim, n, x, k, y, root;

void ap_dfs( int u, int par ) {
	tim++;
	low[u] = tim;
	d[u] = tim;
	vis[u] = 1;
	int cnt = 0, v;
	for(int i=0; i<G[u].size(); i++) {
		v = G[u][i];
		if( v == par ) continue;
        if( !vis[v] ) {
			ap_dfs( v, u );
			low[u] = min( low[u], low[v] );
			if( d[u] < low[v] ) {
				bridges.push_back( { min( u , v ) , max( u, v ) } );
			}
			cnt++;
        } else {
			low[u] = min( low[u], d[v] );
        }
	}
}

int main() {
#ifdef LU_SERIOUS
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
#endif // LU_SERIOUS
	int t;
	scanf("%d", &t);
	for(int cs=1; cs<=t; cs++) {
		memset( low, 0, sizeof low );
		memset( vis, 0, sizeof vis );
		memset( d, 0, sizeof d );
		tim = 0;
		bridges.clear();
		for(int i=0; i<=n; i++) G[i].clear();
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d (%d)", &x, &k);
			for(int i=0; i<k; i++) {
				scanf("%d", &y);
				G[x].push_back( y );
				G[y].push_back( x );
			}
		}
		for(int i=1; i<=n; i++) {
			if( !vis[i] ) {
				root = i;
				ap_dfs( i , - 1 );
			}
		}
		sort( bridges.begin(), bridges.end() );
		printf("Case %d:\n", cs);
		printf("%d critical links\n", bridges.size());
		for(int i=0; i<bridges.size(); i++) {
			printf("%d - %d\n", bridges[i].first, bridges[i].second);
		}
	}
	return 0;
}