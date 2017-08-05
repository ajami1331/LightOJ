#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector < int > digit;
ll lim;
ll dp[3][3][31][31][3];
int vis[3][3][31][31][3];
int tcase, tt;

ll rec( bool start, bool small, int pos, ll value, int prev ) {
    if( pos == lim ) return value;
    ll &ret = dp[start][small][pos][value][prev];
    int &v = vis[start][small][pos][value][prev];
    if( v == tt ) return ret;
    v = tt;
    int sesh = small ? 1 : digit[pos];
    ret = 0;
    if( !start ) {
        for( int i=0; i<=sesh; i++ ) {
            ret += rec( false, small || i < digit[pos], pos+1, ( i & prev ) + value, i );
        }
    } else {
        for( int i=1; i<=sesh; i++ ) {
            ret += rec( false, small || i < digit[pos], pos+1, ( i & prev ) + value, i );
        }
        ret += rec( true, true, pos + 1, 0, 0 );
    }
    return ret;
}

ll calc( ll n ) {

    digit.clear();

    while( n ) {
        digit.push_back( n&1 );
        n >>= 1;
    }

    lim = digit.size();

    reverse( digit.begin(), digit.end() );

    tt++;
    return rec( true, false, 0, 0, 0 );
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    ll n, m;
    scanf( "%d", &tcase );
    for( int cs=1; cs<=tcase; cs++ ) {
        scanf( "%lld", &n );
        printf( "Case %d: %lld\n", cs, calc( n ) );
    }
    return 0;
}
