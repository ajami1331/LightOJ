#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e5 + 1;
const int mod = 1000000007;
int ar[mx], tr[mx], br[mx];
map < int, int > mp;
int n, cn, ans, h;

void up( int x, int v ) {
    for( ; x <= cn; x += x&-x )
        tr[x] = ( tr[x] + v ) % mod;
}

int qu( int x ) {
    int ret = 0;
    for( ; x ; x -= x&-x )
        ret = ( ret + tr[x] ) % mod;
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) scanf( "%d", ar+i ), br[i] = ar[i];
        mp.clear();
        sort( ar, ar+n );
        cn = 0;
        for( int i=0; i<n; i++ ) if( !mp[ ar[i] ] ) mp[ ar[i] ] = ++cn;
        for( int i=0; i<n; i++ ) br[i] = mp[ br[i] ];
        memset( tr, 0, sizeof tr );
        ans = 0;
        for( int i=0; i<n; i++ ) {
            h = qu( br[i] - 1 );
            up( br[i], h + 1 );
        }
//        for( int i=0; i<n; i++ ) cerr << tr[i] << " "; cerr << "\n";
        ans = qu( cn );
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
