#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector < int > digit;
ll lim;
ll dp[3][3][31][31];
int vis[3][3][31][31];
int tcase, tt;

ll rec( bool start, bool small, int pos, int value ) {
    if( pos == lim ) return value;
    ll &ret = dp[start][small][pos][value];
    int &v = vis[start][small][pos][value];
    if( v == tt ) return ret;
    v = tt;
    int sesh = small ? 9 : digit[pos];
    ret = 0;
    if( !start ) {
        for( int i=0; i<=sesh; i++ ) {
            ret += rec( false, small || i < digit[pos], pos+1, ( i == 0 ) + value );
        }
    } else {
        for( int i=1; i<=sesh; i++ ) {
            ret += rec( false, small || i < digit[pos], pos+1, ( i == 0 ) + value );
        }
        ret += rec( true, true, pos + 1, 0 );
    }
    return ret;
}

ll calc( ll n ) {
    if( n < 0 ) return 0;
    if( n <= 9 ) return 1;

    digit.clear();

    while( n ) {
        digit.push_back( n%10 );
        n /= 10;
    }

    lim = digit.size();

    reverse( digit.begin(), digit.end() );

    tt++;
    return rec( true, false, 0, 0 ) + 1;
}

int main() {
    ll n, m;
    scanf( "%d", &tcase );
    for( int cs=1; cs<=tcase; cs++ ) {
        scanf( "%lld %lld", &m, &n );
        printf( "Case %d: %lld\n", cs, calc( n ) - calc( m-1 ) );
    }
    return 0;
}
