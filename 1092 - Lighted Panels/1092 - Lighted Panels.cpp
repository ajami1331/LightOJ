#include <bits/stdc++.h>
using namespace std;

//using ll = long long;

const int sz = 1e5 + 10;
const int mod = 1e9 + 7;

int t, cs, n, m;
char s[9][8];
int dp[8][256][256];

int get_mask( int pos ) {
        int mask = 0;
        for( int i=0; i<m; i++ ) mask |= ( 1 << i ) * ( s[pos][i] == '*' );
        return mask;
}

int change_mask( int mask, int pos ) {
        mask ^= ( 1 << pos );
        if( pos > 0 ) mask ^= ( 1 << ( pos - 1 ) );
        if( pos + 1 != m ) mask ^= ( 1 << ( pos + 1 ) );
        return mask;
}

int rec( int pos, int pre, int now );

int gen( int x, int y, int pre, int now, int next );

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<n; i++ ) scanf( "%s", s[i] );

                for( int i=0; i<m; i++ ) s[n][i] = '.';

                memset( dp, -1, sizeof dp );

                if( rec( 0, 0, get_mask( 0 ) ) >= ( 1 << 28 ) ) printf( "Case %d: impossible\n", cs );

                else printf( "Case %d: %d\n", cs, rec( 0, 0, get_mask( 0 ) ) );

        }

        return 0;
}

int gen( int x, int y, int pre, int now, int next ) {
        if( y == m ) {
                if( !x || ( pre == ( 1 << m ) - 1 ) ) return rec( x + 1, now, next );
                return 1 << 28;
        }
        int ret = 1 << 28;
        ret = min( ret, gen( x, y + 1, pre, now, next ) );
        ret = min( ret, gen( x, y + 1, change_mask( pre, y ), change_mask( now, y ), change_mask( next, y ) ) + 1 );
        return ret;
}

int rec( int pos, int pre, int now ) {
        if( pos == n ) {
                if( pre == ( 1 << m ) - 1 ) return 0;
                return 1 << 28;
        }
        int& ret = dp[pos][pre][now];
        if( ~ret ) return ret;
        ret = 1 << 28;
        ret = min( ret, gen( pos, 0, pre, now, get_mask( pos + 1 ) ) );
        return ret;
}
