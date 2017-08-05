#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;
bitset < mx > fl;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, m;
vector < ll > prime;

void init() {
    int sqn = mx - 10;
    for( int i=4; i<=sqn; i+=2 ) fl[i] = 1;
    for( ll i=3; i*i<=sqn; i+=2 ) {
        if( !fl[i] )
        for( ll j=i*i; j<=sqn; j+=i+i ) {
            fl[j] = 1;
        }
    }
    prime.push_back( 2 );
    for( int i=3; i<=sqn; i+=2 ) if( !fl[i] ) prime.push_back( i );
}

ll big_mod( ll b, ll p ) {
    ll ret = 1;
    for( ; p; p >>= 1 ) {
        if( p&1 ) ret = ( ret * b ) % mod;
        b = ( b * b ) % mod;
    }
    return ret % mod;
}

ll ans() {
    ll ret = 1, cnt, h;
    for( int i=0; i < prime.size() && prime[i]*prime[i] <= n; i++ ) {
        if( n % prime[i] == 0 ) {
            cnt = 0;
            while( n % prime[i] == 0 ) {
                n /= prime[i];
                cnt++;
            }
            cnt *= m;
            cnt++;
            h = ( ( ( big_mod( prime[i], cnt ) - 1LL + mod ) % mod ) * big_mod( prime[i] - 1LL, mod - 2LL ) ) % mod;
            ret = ( ret * h ) % mod;
//            cerr << ( big_mod( prime[i], cnt + 1 ) - 1 ) << " - " << ( powl( prime[i], cnt + 1 ) - 1 ) << "\n";
        }
    }
    if( n > 1 ) {
        h = ( ( ( big_mod( n, m + 1LL ) - 1LL + mod ) % mod ) * big_mod( n - 1LL, mod - 2LL ) ) % mod;
        ret = ( ret * h ) % mod;
    }
    return ret % mod;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    init();
    int t, cs = 0;
    scanf( "%d", &t );
    while( t-- && ~scanf( "%lld %lld", &n, &m ) ) {
        printf( "Case %d: %lld\n", ++cs, ans() );
//        cerr << "-----\n";
    }
    return 0;
}
