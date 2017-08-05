#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
string a, b, dps[101][101];

string rec( int i, int j ) {
    if( i == a.size() || b.size() == j ) return "";
    if( ~dp[i][j] ) return dps[i][j];
    dp[i][j] = 1;
    if( a[i] == b[j] ) {
        dps[i][j] = a[i] + rec( i+1, j+1 );
    } else {
        string ret1 = rec( i+1, j );
        string ret2 = rec( i, j+1 );
        if( ret1.size() > ret2.size() ) {
            dps[i][j] = ret1;
        } else if( ret1.size() < ret2.size() ) {
            dps[i][j] = ret2;
        } else {
            dps[i][j] = min( ret1, ret2 );
        }
    }
    return dps[i][j];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, x, y, n, m, h;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        cin >> a >> b;
//        reverse( a.begin(), a.end() );
//        reverse( b.begin(), b.end() );
//        a += ".";
//        b += ".";
        memset( dp, -1, sizeof dp );
        printf( "Case %d: %s\n", cs, rec( 0, 0 ).size() == 0 ? ":(" : dps[0][0].c_str() );
    }
    return 0;
}
