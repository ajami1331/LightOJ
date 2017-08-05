#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6+10;
double fac[mx];

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif /// CLown1331
    for( int i=1; i<mx; i++ ) {
        fac[i] = log( i );
        if( i ) fac[i] += fac[i-1];
    }
    int t, n, b;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &b );
        printf( "Case %d: %d\n", cs, int( floor( fac[n] / log(b) ) ) + 1  );
    }
    return 0;
}

