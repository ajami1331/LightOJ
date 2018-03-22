#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll sz = 1e4 + 10;
int t, n, cs, _xor;
int grundy[sz];

void get_val( int x ) {
        set < int > st;
        for( int i=1; i<=x; i++ ) {
                int j = x - i;
                if( i >= j ) break;
                if( i != j ) {
                        st.insert( grundy[i] ^ grundy[j] );
                }
        }
        for( int i=0; i<sz; i++ ) {
                if( st.find( i ) == st.end() ) {
                        grundy[x] = i;
                        break;
                }
        }
}

int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        for( int i=0; i<sz; i++ ) get_val( i );

        scanf( "%lld", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                _xor = 0;

                for( int i=0; i<n; i++ ) {
                        int x;
                        scanf( "%d", &x );
                        _xor ^= grundy[x];
                }

                printf( "Case %d: %s\n", cs, _xor ? "Alice" : "Bob" );

        }
        return 0;
}
