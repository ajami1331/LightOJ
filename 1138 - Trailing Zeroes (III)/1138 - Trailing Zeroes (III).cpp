#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;
int t, cs, n, m;
int ans;

int check( int x ) {
        int ret = 0;
        while( x > 0 ) {
                x /= 5;
                ret += x;
        }
        return ret;
}

int solve() {
        int lo = 0, hi = 1 << 30;
        int mid;
        while( hi - lo > 4 ) {
                mid = ( lo + hi ) / 2;
                if( check( mid ) >= n ) hi = mid;
                else lo = mid;
        }
        ans = -1;
        for( ; lo<=hi; lo++ ) if( check( lo ) == n ) {
                ans = lo;
                break;
        }
        return ans != -1;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                printf( "Case %d: ", cs );

                if( solve() ) printf( "%d\n", ans );
                else printf( "impossible\n" );

//                cerr << "----\n";
        }

        return 0;
}
