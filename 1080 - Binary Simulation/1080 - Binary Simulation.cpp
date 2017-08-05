#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;
int fenw[mx], N;
char s[mx];

void update( int idx, int v ) {
    for( ; idx <= N; idx += ( idx & -idx ) ) {
        fenw[idx] += v;
    }
}

void up_( int x, int y ) {
    update( x, 1 );
    update( y+1, -1 );
}

int query( int idx ) {
    int sum = 0;
    for( ; idx; idx -= ( idx & -idx ) ) {
        sum += fenw[idx];
    }
    return sum & 1;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, x, y, q;
    char c;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%s %d", s, &q );
        N = strlen( s );
//        reverse( s.begin(), s.end() );
        memset( fenw, 0, sizeof fenw );
        printf( "Case %d:\n", cs );
        while( q-- ) {
            scanf( "%*c%c%*c", &c );
//            cerr << c << " ";
            if( c == 'Q' ) {
                scanf( "%d", &x );
//                cerr << x << "\n";
                printf( "%d\n", ( ( s[x-1] + query( x ) ) & 1 ) );
            } else {
                scanf( "%d %d", &x, &y );
//                cerr << x << " " << y << "\n";
                up_( x, y );
            }
        }
    }
    return 0;
}
