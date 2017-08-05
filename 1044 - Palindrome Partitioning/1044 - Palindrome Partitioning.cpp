#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int inf = 1e9;
const int mx = 1001;
char str[mx];
int t, cs;
int dp[mx], vis[mx], len;

bool check( int i, int j ) {
    for( ; i<j; i++, j-- ) {
        if( str[i] != str[j] ) return false;
    }
    return true;
}

int rec( int pos ) {
    if( pos >= len ) return 0;
    if( vis[pos] == cs ) return dp[pos];
    vis[pos] = cs;
    int &ret = dp[pos];
    ret = inf;
    for( int i=pos; i<len; i++ ) {
        if( check( pos, i ) ) {
            ret = min( 1 + rec( i+1 ), ret );
        }
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%s", str );
        len = strlen( str );
        printf( "Case %d: %d\n", cs, rec( 0 ) );
    }
    return 0;
}
