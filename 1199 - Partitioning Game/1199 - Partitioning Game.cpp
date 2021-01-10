#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll sz = 2e4 + 10;
int t, n, cs, _xor;
int grundy[sz];
bool mark[sz];
int hand[sz];

void get_val( int x ) {
        int cnt = 0;
        for( int i=1; i<=x; i++ ) {
                int j = x - i;
                if( i >= j ) break;
                if( i != j ) {
                        mark[grundy[i] ^ grundy[j]] = 1;
                        hand[cnt++] = grundy[i] ^ grundy[j];
                }
        }
        for( int i=0; i<sz; i++ ) {
                if(mark[i] == 0) {
                        grundy[x] = i;
                        break;
                }
        }
        for (int i = 0; i < cnt; i++) {
                mark[i] = 0;
        }
}

int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        for( int i=0; i<sz; i++ ) get_val( i );

        scanf( "%d", &t );

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
