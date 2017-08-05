#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int inf = 1e9;
int dp[1001][2], ar[1001], n;

int rec( int i, bool f ) {
    if( i >= n ) return 0;
    if( i == n - 1 )
        if( !f ) return ar[i];
        else return 0;
    if( ~dp[i][f] ) return dp[i][f];
    int &ret = dp[i][f];
    if( !i ) ret = max( ar[i] + rec( i+2, 1 ), rec( i+1, f ) );
    else ret = max( ar[i] + rec( i+2, f ), rec( i+1, f ) );
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) scanf( "%d", ar+i );
        memset( dp, -1, sizeof dp );
        printf( "Case %d: %d\n", cs, rec( 0, 0 ) );
    }
    return 0;
}
