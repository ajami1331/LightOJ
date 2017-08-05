#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;

int solve( int x1, int y1, int x2, int y2 ) {
    int c1, c2;

    if( x1 & 1 && y1 & 1 )  c1 = 1;
    if( x1 & 1 && !( y1 & 1 ) )  c1 = 0;
    if( !( x1 & 1 ) && y1 & 1 )  c1 = 0;
    if( !( x1 & 1 ) && !( y1 & 1 ) )  c1 = 1;

    if( x2 & 1 && y2 & 1 )  c2 = 1;
    if( x2 & 1 && !( y2 & 1 ) )  c2 = 0;
    if( !( x2 & 1 ) && y2 & 1 )  c2 = 0;
    if( !( x2 & 1 ) && !( y2 & 1 ) )  c2 = 1;

    if( c1 != c2 ) return 0;

    if( ( ( x1 + y1 ) == ( x2 + y2 ) ) || ( ( x1 - y1 ) == ( x2 - y2 ) ) ) return 1;

    return 2;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, k, x1, y1, x2, y2;;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
        k = solve( x1, y1, x2, y2 );
        if( k ) printf( "Case %d: %d\n", cs, k );
        else printf( "Case %d: impossible\n", cs );
    }
    return 0;
}
