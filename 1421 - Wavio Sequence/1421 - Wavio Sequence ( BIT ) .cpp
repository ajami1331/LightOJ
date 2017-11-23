#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int sz = 1e5 + 10;
int n;
int ar[sz];
int br[sz];
int l[2][sz];
int tr[2][sz];

int query( int ty, int x ) {
    int ret = 0;
    for( ; x>0; x-=(x&-x) ) ret = max( tr[ty][x], ret );
    return ret;
}

int update( int ty, int x, int v ) {
    for( ; x<sz; x+=(x&-x) ) tr[ty][x] = max( v, tr[ty][x] );
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    int cs = 0, t;
    scanf( "%d", &t );
    while( t-- && scanf( "%d", &n ) == 1 ){
        memset( ar, 0, sizeof ar );
        memset( br, 0, sizeof br );
        memset( tr, 0, sizeof tr );
        memset( l, 0, sizeof l );
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &ar[i] );
            br[i] = ar[i];
        }
        sort( br, br + n );
        int mx = sz - 2;
        for( int i=0; i<n; i++ ) {
            ar[i] = ( lower_bound( br, br + n, ar[i] ) - br ) + 1;
        }
        for( int i=0; i<n; i++ ) {
            l[0][i] = query( 0, ar[i] - 1 ) + 1;
            update( 0, ar[i], l[0][i] );
        }
        reverse( ar, ar + n );
        for( int i=0; i<n; i++ ) {
            l[1][n - i - 1] = query( 1, ar[i] - 1 ) + 1;
            update( 1, ar[i], l[1][n - i - 1] );
        }
        int ans = 0;
        for( int i=0; i<n; i++ ) ans = max( ans, min( l[0][i], l[1][i] ) * 2 - 1 );
        printf( "Case %d: %d\n", ++cs, ans );
    }
    return 0;
}
