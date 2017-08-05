#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll smx = 1e5;
const ll mx = 1e10 + 1;
const int cata = 2e5;
vector < ll > powr;
set < ll > st;
const ll mod = 100000007;
ll dp[cata];

ll rec( int idx ) {
    if( ~dp[idx] ) return dp[idx];
    ll &ret = dp[idx];
    ret = 0;
    for( int i=0; i<idx; i++ ) {
        ret += ( rec( i ) * rec( idx - i - 1 ) );
        ret %= mod;
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    for( ll i=2; i<=smx; i++ ) {
        ll x = i * i;
        while( x <= mx ){
			st.insert( x );
			x *= i;
		}
    }
    memset( dp, -1, sizeof dp );
    for( set < ll > :: iterator it = st.begin(); it != st.end(); ++it ) {
        powr.push_back( *it );
    }
//    cerr << powr.size() << "\n";
    dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 5;
    ll a, b, n, ans, x, y;
    int t, cs;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%lld %lld", &a, &b );
        n = ( upper_bound( powr.begin(), powr.end(), b ) - lower_bound( powr.begin(), powr.end(), a ) );
//        cout << n << " ";
        if( n <= 0 ) ans = 0;
        else ans = rec( n );
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}

