#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1 << 17;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, lim;
ll a, b;
ll ar[20];
ll dp[20][20][2][2][2];

ll rec( int x, int y, int st, int sf, int sb ) {
        cerr << x << " " << y << " " << st << " " << sf << " " << sb << "\n";
        if( x > y ) return st && ( sf || sb );
        ll& ret = dp[x][y][st][sf][sb];
        if( ~ret ) return ret;
        ret = 0;
        int en = sf ? 9 : ar[x];
        if( st ) {
                for( int i=0; i<=en; i++ ) {
                        ret += rec( x + 1, y - 1, 1, sf | ( i < en ), sb | ( i < ar[y] ) );
                }
        }
        else {
                for( int i=1; i<=en; i++ ) {
                        ret += rec( x + 1, y - 1, 1, sf | ( i < en ), sb | ( i < ar[y] ) );
                }
                ret += rec( x + 1, y, 0, 1, 1 );
        }
        return ret;
}

ll solve( ll x ) {
        if( x < 0 ) return 0;
        if( x == 0 ) return 1;
        lim = 0;
        while( x > 0 ) {
                ar[lim++] = x % 10;
                x /= 10;
        }
        reverse( ar, ar + lim );
        memset( dp, -1, sizeof dp );
        return rec( 0, lim - 1, 0, 0, 0 ) + 1;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lld %lld", &a, &b );

                if( a > b ) swap( a, b );

                printf( "Case %d: %lld\n", cs, solve( b ) - solve( a - 1 ) );

        }
 
        return 0;
}
