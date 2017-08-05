#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;
char str[21][21];
int dp[17][1<<16];
int vv[17][1<<16];
int t, n, m, cs, l, ans;
vector < pair < int, int > > vp;
pair < int, int > xy;

int dist( pair < int, int > x, pair < int, int > y ) {
    return max( abs( x.first - y.first ), abs( x.second - y.second ) );
}

bool check( int mask, int pos ) {
    return mask & ( 1 << pos );
}

int Set( int mask, int pos ) {
    return mask | ( 1 << pos );
}

int rec( int pos, int mask ) {
    if( mask == ( 1 << l ) - 1 ) {
        return dist( xy, vp[pos] );
    }
    if( vv[pos][mask] == cs ) return dp[pos][mask];
    int &ret = dp[pos][mask];
    vv[pos][mask] = cs;
    ret = inf;
    for( int i=0; i<l; i++ ) {
        if( !check( mask, i ) ) {
            ret = min( ret, dist( vp[i], vp[pos] ) + rec( i, Set( mask, i ) ) );
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
        vp.clear();
        scanf( "%d %d", &n, &m );
        for( int i=0; i<n; i++ ) {
            scanf( "%s", str[i] );
            for( int j=0; j<m; j++ ) {
                if( str[i][j] == 'x' ) {
                    xy.first = i;
                    xy.second = j;
                }
                if( str[i][j] == 'g' ) {
                    vp.push_back( { i, j } );
                }
            }
        }
        l = vp.size();
        ans = inf;
        for( int i=0; i<l; i++ ) {
            ans = min( ans, dist( vp[i], xy ) + rec( i, 1 << i ) );
        }
        if( ans == inf ) ans = 0;
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
