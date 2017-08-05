#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1005;
int tree[mx][mx];
bool fl[mx][mx];

void update_y( int x, int y ) {
    for( ; y<mx; y+=(y&-y) ) {
        tree[x][y]++;
    }
}

void update( int x, int y ) {
    for( ; x<mx; x+=(x&-x) ) {
        update_y( x, y );
    }
}

int query_y( int x, int y ) {
    int ret = 0;
    for( ; y; y-=(y&-y) ) {
        ret += tree[x][y];
    }
    return ret;
}

int query( int x, int y ) {
    int ret = 0;
    for( ; x; x-=(x&-x) ) {
        ret += query_y( x, y );
    }
    return ret;
}

int query( int x1, int y1, int x2, int y2 ) {
    return ( query( x2, y2 ) - query( x2, y1-1 ) - query( x1-1, y2 ) + query( x1-1, y1-1 ) );
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, q, x, y, x1, y1, x2, y2, k;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &q );
        memset( fl, 0, sizeof fl );
        memset( tree, 0, sizeof tree );
        printf( "Case %d:\n", cs );
        while( q-- ) {
            scanf( "%d", &k );
            if( k ) {
                scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
//                cerr << k << " " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
                printf( "%d\n", query( x1+1, y1+1, x2+1, y2+1 ) );
            } else {
                scanf( "%d %d", &x, &y );
                if( fl[x][y] ) continue;
                fl[x][y] = 1;
                update( x+1, y+1 );
            }
        }

    }
    return 0;
}
