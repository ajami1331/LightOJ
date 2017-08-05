#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int sz = 1e5 + 10;
map < int, int > mp;

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif /// CLown1331
    int t, cs, n, x;
    ll ans;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        mp.clear();
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &x );
            mp[x]++;
        }
        ans = 0LL;
        for( map < int, int > :: iterator it = mp.begin(); it != mp.end(); ++it ) {
            ans += ( it-> second / ( it->first + 1 ) ) * ( it->first + 1 );
            if( it-> second % ( it->first + 1 ) ) ans += ( it->first + 1 );
        }
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
