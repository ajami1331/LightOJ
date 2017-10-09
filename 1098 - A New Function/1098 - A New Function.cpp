#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    int t;
    long long n, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%lld", &n );
        ans = 0;
        for( long long i=2,j; i * i <= n; i++ ) {
            j = n / i;
            ans += ( i + j ) * ( j - i + 1 ) / 2;
            ans += i * ( j - i );
        }
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
