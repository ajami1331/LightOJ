#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, cs, t, k, pp;
const ll mod = 1e9 + 7;
int dp[60];
char s[66];

int main() {
    #ifdef CLown1331
        freopen("in.txt", "r", stdin);
    #endif // CLown1331
    dp[0] = 1;
    dp[1] = 1;
    for( int i=2; dp[i-1]<mod; i++ ) dp[i] = dp[i-1] + dp[i-2];
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        k = 0;
        while( dp[k] <=n ) k++;
        k--;
        pp = 0;
        while( n ) {
            if( dp[k] <= n ) {
                s[pp++] = '1';
                n -= dp[k];
            } else s[pp++] = '0';
            k--;
        }
        while( k-- ) s[pp++] = '0';
        s[pp] = '\0';
        printf( "Case %d: %s\n", cs, s );
    }
    return 0;
}
