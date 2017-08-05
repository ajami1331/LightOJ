#include <bits/stdc++.h>
using namespace std;

const int mx = 2e4 + 10;
int vis[mx];
int n, t, x, y, on, tw, ans;
vector < int > G[mx];

void dfs(int u,int colr) {
	vis[u] = colr;
	tw += colr == 2;
	on += colr == 1;
	for(int i=0; i<G[u].size(); i++) {
		if( !vis[ G[u][i] ] ) {
			dfs( G[u][i], colr == 1 ? 2 : 1 );
		}
	}
}

int main() {
#ifdef LU_SERIOUS
	freopen("in.txt", "r", stdin);
#endif // LU_SERIOUS
	scanf("%d", &t);
	for(int cs=1; cs<=t; cs++) {
		scanf("%d", &n);
		for(int i=0; i<mx; i++) G[i].clear();
		memset( vis, 0, sizeof vis );
		while( n-- ) {
			scanf("%d %d", &x, &y);
			G[x].push_back( y );
			G[y].push_back( x );
		}
		ans = 0;
		for(int i=0; i<mx; i++) {
			if( G[i].empty() ) continue;
			tw = 0; on = 0;
			if( !vis[i] )
				dfs( i, 1 );
			ans += max( tw, on );
		}
		printf("Case %d: %d\n", cs, ans );
	}
	return 0;
}