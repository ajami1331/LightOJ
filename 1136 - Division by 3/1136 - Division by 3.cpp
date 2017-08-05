#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;

int cnt( int a ) {
    int ret = a / 3;
    ret *= 2;
    if( a % 3 == 2 ) ret++;
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, k, q;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &q );
        printf( "Case %d: %d\n", cs, cnt( q ) - cnt( n-1 ) );
    }
    return 0;
}
