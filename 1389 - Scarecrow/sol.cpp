#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e5 + 10;
const ll mod = 1000007;

int n;
char s[105];
int dp[105];

int rec( int x ) {
        if( x >= n ) return 0;
        return ( s[x] == '.' ) ? rec( x + 3 ) + 1 : rec( x + 1 );
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                scanf( "%s", s );

                printf( "Case %d: %d\n", cs, rec( 0 ) );

        }

        return 0;
}