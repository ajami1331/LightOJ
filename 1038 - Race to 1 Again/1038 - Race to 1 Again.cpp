#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;
int n, t, cs;
int vis[mx];
double dp[mx];

double rec( int d ) {
    if( d == 1 ) return 0.0;
    if( vis[d] == cs ) return dp[d];
    int sqt = sqrt( d ) + 1, cnt = 2;
    dp[d] = 2.0;
    for( int i=2; i<sqt; i++ ) {
        if( d % i == 0 ) {
            if( d / i == i ) {
                dp[d] += 1 + rec( i );
                cnt++;
            } else {
                dp[d] += 1 + rec( d / i );
                dp[d] += 1 + rec( i );
                cnt += 2;
            }
        }
    }
    --cnt;
    return dp[d] /= cnt;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        printf( "Case %d: %.7lf\n", cs, rec( n ) );
    }
    return 0;
}
