#include <bits/stdc++.h>
using namespace std;

int n, m, t, ans;

int main() {
#ifdef LU_SERIOUS
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w+", stdout);
#endif // LU_SERIOUS
	scanf("%d", &t);
	for(int cs=1; cs<=t; cs++) {
		scanf("%d %d", &n, &m);
		ans = ( ( n * m ) + 1 ) / 2;
		if( n > m ) swap( n, m );
		if( n == 1 ) ans = m;
		else if( n == 2 ) {
			ans = ( m / 4 ) * 4;
			if( m % 4 == 1 ) {
				ans += 2;
			} else if( m % 4 > 1 ) {
				ans += 4;
			}
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}