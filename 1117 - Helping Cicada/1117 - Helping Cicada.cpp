#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 1;
typedef long long int ll;
ll lcm, ans, ar[16], n;

ll __lcm( ll a, ll b ) {
    return ( a / __gcd( a, b ) ) * b;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, m, chol, cnt;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%lld %d", &n, &m );
        for( int i=0; i<m; i++ ) scanf( "%lld", &ar[i] );
        chol = 1 << m; ans = 0;
        for( int mask=1; mask<chol; mask++ ) {
            lcm = 1; cnt = 0;
            for( int i=0; i<m; i++ ) {
                if( mask & ( 1 << i ) ) {
                    lcm = __lcm( lcm, ar[i] );
                    cnt++;
                }
            }
            //cerr << lcm << " " << n / lcm << " " << cnt << "\n";
            if( cnt & 1 ) ans += n / lcm;
            else ans -= n / lcm;
        }
        //cerr << ans << " ";
        printf( "Case %d: %lld\n", cs, n - ans );
    }
    return 0;
}
