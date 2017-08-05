#include <bits/stdc++.h>
using namespace std;

char s[61];
int len;
long long dp[61][61];

long long rec( int i, int j ) {
    if( i == j ) return 1;
    if( i > j ) return 0;
    if( ~dp[i][j] ) return dp[i][j];
    dp[i][j] = 0;
    if( s[i] == s[j] ) dp[i][j] += rec( i+1, j-1 ) + 1;
    dp[i][j] += rec( i+1, j ) + rec( i, j-1 ) - rec( i+1, j-1 );
    return dp[i][j];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%s", s );
        len = strlen( s );
        memset( dp, -1, sizeof dp );
        printf( "Case %d: %lld\n", cs, rec( 0, len-1 ) );
    }
    return 0;
}
