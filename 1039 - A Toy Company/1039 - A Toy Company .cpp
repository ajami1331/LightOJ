#include <bits/stdc++.h>
using namespace std;

int vis[26][26][26];

int main() {
#ifdef LU_SERIOUS
	freopen("in.txt", "r", stdin);
#endif // LU_SERIOUS
	int t, k;
	string s, d, a, b, c;
	scanf("%d", &t);
	for(int cs=1; cs<=t; cs++) {
		cin >> s >> d >> k;
		memeset( vis, 0, sizeof vis );
		for(int i=0; i<k; i++) {
			cin >> a >> b >> c;
			for(int j=0; j<a.size(); j++) {
				for(int k=0; k<a.size(); k++) {
					for(int l=0; l<c.size(); l++) {
						vis[ a[j]-'a' ][ b[k]-'a' ][ c[l]-'a' ] = -1;
					}
				}
			}
		}
		printf("Case %d: %d\n", cs, bfs( s, d ) );
	}
	return 0;
}