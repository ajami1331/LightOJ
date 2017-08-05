#include <bits/stdc++.h>
using namespace std;

int n;
bool memo[101];
double ar[101];
double dp[101];

double rec( int i ) {
    if( i == n-1 ) return ar[i];
    if( memo[i] ) return dp[i];
    memo[i] = 1;
    int pos = min( 6, (n-1)-i );
    double prob = 1.0 / pos;
    dp[i] = ar[i];
    for( int j=1; j<=pos; j++ ) {
        dp[i] += prob * rec( i+j );
    }
    return dp[i];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) scanf( "%lf", &ar[i] );
        memset( memo, 0, sizeof memo );
        printf( "Case %d: %lf\n", cs, rec( 0 ) );
    }
    return 0;
}
