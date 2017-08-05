#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int inf = 1e9;
int dp[51][51][51], aa, bb, cc;
char a[51], b[51], c[51];

int rec( int i, int j, int k ) {
    if( i == aa || j == bb || k == cc ) return 0;
    if( ~dp[i][j][k] ) return dp[i][j][k];
    if( a[i] == b[j] && b[j] == c[k] ) return dp[i][j][k] = 1 + rec( i+1, j+1, k+1 );
    dp[i][j][k] = max( max( rec( i+1, j, k ), rec( i, j+1, k ) ), rec( i, j, k+1 ) );
    return dp[i][j][k];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%s", a );
        scanf( "%s", b );
        scanf( "%s", c );
        aa = strlen( a );
        bb = strlen( b );
        cc = strlen( c );
        memset( dp, -1, sizeof dp );
        printf( "Case %d: %d\n", cs, rec( 0, 0, 0 ) );
    }
    return 0;
}
