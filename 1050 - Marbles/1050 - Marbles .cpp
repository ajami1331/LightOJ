#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 1;
typedef long long int ll;
double dp[511][511][2];
bool vis[511][511][2];

double rec( int i, int j, int k ) {
    if( vis[i][j][k] ) return dp[i][j][k];
    if( i + j == 1 ) return dp[i][j][k] = j;
    vis[i][j][k] = 1;
    double &ret = dp[i][j][k];
    ret = 0;
    if( !k ) {
        if( i > 0 ) ret += rec( i-1, j, !k ) * ( (double)i/(i+j) );
        if( j > 0 ) ret += rec( i, j-1, !k ) * ( (double)j/(i+j) );
    } else {
        if( j > 0 ) ret += rec( i, j-1, !k );
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, r, b;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &r, &b );
        printf( "Case %d: %.12f\n", cs, rec( r, b, 0 ) );
    }
    return 0;
}
