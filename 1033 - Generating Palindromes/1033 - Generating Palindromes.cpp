#include <bits/stdc++.h>
using namespace std;

string s;
int t, cs;
int dp[127][127];

int rec( int i, int j ) {
    if( i >= j ) return 0;
    if( ~dp[i][j] ) return dp[i][j];
    if( s[i] == s[j] ) dp[i][j] = rec( i+1, j-1 );
    else dp[i][j] = 1 + min( rec( i+1, j ), rec( i, j-1 ) );
    return dp[i][j];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        cin >> s;
        memset( dp, -1, sizeof dp );
        printf( "Case %d: %d\n", cs, rec( 0, s.size()-1 ) );
    }
    return 0;
}

