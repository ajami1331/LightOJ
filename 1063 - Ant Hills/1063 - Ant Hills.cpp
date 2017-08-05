#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 +  10;
vector < int > G[mx];
int tim, root, n, m, a, b;
int ap[mx], vis[mx], low[mx], d[mx], par[mx];

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
			if( d[u] <= low[v] && u != root ) {
				ap[u] = 1;
			}
			cnt++;
        } else {
			low[u] = min( low[u], d[v] );
        }
        if( u == root && cnt > 1 ) ap[u] = 1;
	}
}

int main() {
#ifdef LU_SERIOUS
	freopen("in.txt", "r", stdin);
#endif // LU_SERIOUS
	int t;
	scanf("%d", &t);
	for(int cs=1; cs<=t; cs++) {
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++) {
			G[i].clear();
			vis[i] = 0;
			low[i] = 0;
			d[i] = 0;
			par[i] = 0;
			ap[i] = 0;
		}
		for(int i=0; i<m; i++) {
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		tim = 0;
		for(int i=1; i<=n; i++) {
			if( !vis[i] ) {
				root = i;
				ap_dfs( i );
			}
		}
		int ans = 0;
		for(int i=1; i<=n; i++) {
			ans += ap[i];
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}