#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1005;
const ll lim = 1e12 + 3;
#define sqr( a ) ( ( a ) * ( a ) )

int t, ans;
int fac[12];
int freq[12];
char s[12];
int dp[1 << 10][1005];
int d, n;

int rec( int x, int mask, int r ) {
        if( x == n ) {
                return r == 0;
        }
        int& ret = dp[mask][r];
        if( ~ret ) return ret;
        ret = 0;
        for( int i=0; i<n; i++ ) {
                if( mask & ( 1 << i ) ) continue;
                ret += rec( x + 1, mask | ( 1 << i ), ( r * 10 + s[i] ) % d );
        }
        return ret;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        fac[0] = 1;

        for( int i=1; i<12; i++ ) fac[i] = fac[i - 1] * i;

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%s %d", s, &d );

                n = strlen( s );

                sort( s, s + n );

                memset( freq, 0, sizeof freq );

                for( int i=0; i<n; i++ ) s[i] -= '0', freq[s[i]]++;

                ans = 0;

                memset( dp, -1, sizeof dp );

                ans = rec( 0, 0, 0 );

                for( int i=0; i<10; i++ ) {
                        ans /= fac[freq[i]];
                }

                printf( "Case %d: %d\n", cs, ans );
 
        }
 
        return 0;
}
