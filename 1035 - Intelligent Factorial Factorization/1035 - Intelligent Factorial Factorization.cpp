#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int fa[105];

void _do( int x ) {
    for( int i=2; i*i<=x; i++ ) {
        while( x % i == 0 ) {
            fa[i]++;
            x /= i;
        }
    }
    if( x != 1 ) fa[x]++;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif /// CLown1331
    int t, cs, n, st;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        memset( fa, 0, sizeof fa );
        for( int i=2; i<=n; i++ ) {
            _do( i );
        }
        st = 0;
        printf( "Case %d: %d = ", cs, n );
        for( int i=0; i<=n; i++ ) {
            if( fa[i] ) {
                if( st ) printf( " * " );
                printf( "%d (%d)", i, fa[i] );
                st = 1;
            }
        }
        printf( "\n" );
    }
    return 0;
}
