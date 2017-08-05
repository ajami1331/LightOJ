#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int vis[101][101];
int ar[101];
int t, cs, n, w, k;

int rec( int idx, int kk ) {
    if( idx >= n ) return 0;
    if( kk <= 0 ) return 0;
    if( vis[idx][kk] == cs ) return dp[idx][kk];
    vis[idx][kk] = cs;
    int &ret = dp[idx][kk];
    ret = -1;
    ret = max( ret, rec( idx+1, kk ) );
    int cnt = 1;
    for( int i=idx+1; i < n && ar[i] <= ar[idx] + w; i++ ) {
        cnt++;
    }
    ret = max( ret, cnt + rec( idx + cnt, kk - 1 ) );
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", V"w+", stdout );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d", &n, &w, &k );
        for( int i=0; i<n; i++ ) scanf( "%*d %d", &ar[i] );
        sort( ar, ar+n );
        printf( "Case %d: %d\n", cs, rec( 0, k ) );
    }
    return 0;
}
