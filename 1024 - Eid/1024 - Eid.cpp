#include <bits/stdc++.h>
using namespace std;

map < int, int > fac, fac2;
map < int, int > :: iterator it;
string s;

void factorize( int x ) {
    fac2.clear();
    for( int i=2; i*i<=x; i++ ) {
        while( x % i == 0 ) {
            x /= i;
            fac2[i]++;
            fac[i] = max( fac2[i], fac[i] );
        }
    }
    if( x != 1 ) {
        fac[x] = max( 1, fac[x] );
    }
}

void multiply( int x ) {
    int carry = 0;
    for( int i=0; i<s.size(); i++ ) {
        carry += ( s[i] - 48 ) * x;
        s[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        s += ( carry % 10 + 48 );
        carry /= 10;
    }
}

void print() {
    for( int i=s.size()-1; i>=0; i-- ) {
        putchar( s[i] );
    }
    putchar( '\n' );
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    int t, cs, n, a;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        fac.clear();
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &a );
            factorize( a );
        }
        s = "1";
        for( it = fac.begin(); it != fac.end(); ++it ) {
            multiply( powl( it->first, it->second ) );
        }
        printf( "Case %d: ", cs );
        print();
    }
    return 0;
}
