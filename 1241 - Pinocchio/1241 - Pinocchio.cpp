#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int ar[11];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, prev, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        prev = 2; ans = 0;
        for( int i=0; i<n; i++ ) {
            scanf( "%d", ar+i );
            if( ar[i] - prev > 0 ) {
                ans += ( ar[i] - prev ) / 5;
                ans += ( ar[i] - prev ) % 5 ? 1 : 0;
            }
            prev = ar[i];
        }
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
