#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
using ull = unsigned long long;

const int sz = 1005;
#define sqr( a ) ( ( a ) * ( a ) )

int t;
int n, k, mod;
int ar[sz], ans;
int fac[sz], nk;

int big_mod( int b, int p ) {
        int ret = 1;
        for( ; p>0; p >>= 1 ) {
                if( p&1 ) ret = ( ret * b ) % mod;
                b = ( b * b ) % mod;
        }
        return ret % mod;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%d %d %d", &n, &k, &mod );

                for( int i=0; i<n; i++ ) {
                        scanf( "%d", &ar[i] );
                }

                nk = ( big_mod( n, k - 1 ) * ( k % mod ) ) % mod;

                ans = 0;

                for( int i=0; i<n; i++ ) {
                        ans = ( ans + ( ar[i] % mod ) ) % mod;
                }

                ans = ( ans * nk ) % mod;

                printf( "Case %d: %d\n", cs, ans );
        }
 
        return 0;
}
