#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll sz = 1e4 + 10;
int t, n, cs, _xor;

int get_val( int x ) {
        while( x & 1 ) x >>= 1;
        return x;
}

int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        scanf( "%lld", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                _xor = 0;

                for( int i=0; i<n; i++ ) {
                        int x;
                        scanf( "%d", &x );
                        _xor ^= get_val( x );
                }

                printf( "Case %d: %s\n", cs, _xor ? "Alice" : "Bob" );

        }
        return 0;
}
