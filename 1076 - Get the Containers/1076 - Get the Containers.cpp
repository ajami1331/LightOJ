#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int ar[1005];

int check( int mid ) {
        int hand = 0, cnt = 1;
        for( int i=0; i<n; i++ ) {
                if( hand + ar[i] <= mid ) {
                        hand += ar[i];
                } else {
                        hand = ar[i];
                        cnt++;
                }
        }
        return cnt <= m;
}

int solve() {
        int lo = 0, hi = 1e9 + 10, mid;

        for( int i=0; i<n; i++ )
                scanf( "%d", &ar[i] ), lo = max( lo, ar[i] );

        while( hi - lo > 4 ) {
                mid = ( lo + hi ) / 2;
                if( check( mid ) )
                        hi = mid;
                else
                        lo = mid;
        }

        for( ; lo<=hi; lo++ )
                if( check( lo ) )
                        return lo;

        return lo;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                printf( "Case %d: %d\n", cs, solve() );
        }
        return 0;
}

