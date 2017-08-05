#include <bits/stdc++.h>
using namespace std;

char s[27];
int t, cs, n, k, cn;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    for( char c='A'; c<='Z'; c++ ) s[c-'A'] = c;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &k );
        sort( s, s+26 );
        printf( "Case %d:\n", cs );
        cn = 0;
        do {
            for( int i=0; i<n; i++ ) putchar( s[i] ); putchar('\n');
            cn++;
        } while( next_permutation( s, s+n ) && cn < k );
    }
    return 0;
}

