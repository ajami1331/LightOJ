#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, q, d, m, cs, t;
int ar[205];
ll dp[205][11][22];

ll rec( int ii, int cnt, int sum ) {
    if( ii < 0 ) {
        if( !cnt && !sum ) return 1LL;
        return 0;
    }
    if( cnt < 0 ) return 0LL;
    ll &ret = dp[ii][cnt][sum];
    if( ~ret ) return ret;
    ret = ( rec( ii - 1, cnt - 1, ( ( ( sum + ar[ii] ) % d ) + d ) % d ) + rec( ii - 1 , cnt, sum ) );
    return ret;
}

int main() {
    #ifdef CLown1331
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w+", stdout);
    #endif // CLown1331
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &q );
        for( int i=0; i<n; i++ ) scanf( "%d", &ar[i] );
        printf( "Case %d:\n", cs );
        while( q-- ) {
            scanf( "%d %d", &d, &m );
            memset( dp, -1, sizeof dp );
            printf( "%lld\n", rec( n-1, m, 0 ) );
        }
    }
    return 0;
}
