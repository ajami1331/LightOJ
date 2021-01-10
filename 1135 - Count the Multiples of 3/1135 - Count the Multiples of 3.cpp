#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int sz = 1e5 + 10;
int n, q, t, cs, ty, x, y, lazy[sz *4];

struct nd {
    int zero, one, two;
} tr[sz * 4];

void rot( int node ) {
    int a = tr[node].two;
    tr[node].two = tr[node].one;
    tr[node].one = tr[node].zero;
    tr[node].zero = a;
}

void add( int node, int left, int right ) {
    tr[node].zero = tr[left].zero + tr[right].zero;
    tr[node].one = tr[left].one + tr[right].one;
    tr[node].two = tr[left].two + tr[right].two;
}

void build( int node, int b, int e ) {
    if( b == e ) {
        tr[node].zero = 1;
        tr[node].one = 0;
        tr[node].two = 0;
        lazy[node] = 0;
        return;
    }
    int mid = ( b + e ) >> 1 ;
    int left = node << 1;
    int right = left | 1;
    build( left, b, mid );
    build( right, mid+1, e );
    lazy[node] = 0;
    add( node, left, right );
}

void propagate( int node, int left, int right ) {
    lazy[left] = ( lazy[left] + lazy[node] ) % 3;
    lazy[right] = ( lazy[right] + lazy[node] ) % 3;
    if( lazy[node] ) {
        rot( left );
        rot( right );
        if( lazy[node] == 2 ) {
            rot( left );
            rot( right );
        }
    }
    lazy[node] = 0;
}

void upd( int node, int b, int e, int i, int j ) {
    if( i > e || j < b ) {
        return;
    }
    if( b >= i && e <= j ) {
        lazy[node] = ( lazy[node] + 1 ) % 3;
        rot( node );
        return;
    }
    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    propagate( node, left, right );

    upd( left, b, mid, i, j );
    upd( right, mid + 1, e, i, j );

    add( node, left, right );
}

int qu( int node, int b, int e, int i, int j )  {
    if( i > e || j < b ) {
        return 0;
    }
    if( b >= i && e <= j ) {
        return tr[node].zero;
    }
    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    propagate( node, left, right );

    int ret = 0;
    ret += qu( left, b, mid, i, j );
    ret += qu( right, mid + 1, e, i, j );

    return ret;
}

int main() {
    #ifdef CLown1331
        freopen("in.txt", "r", stdin);
    #endif // CLown1331
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &q );
        build( 1, 0, n-1 );
        printf( "Case %d:\n", cs );
        while( q-- ) {
            scanf( "%d %d %d", &ty, &x, &y );
            if( !ty ) {
                upd( 1, 0, n-1, x, y );
            } else {
                printf( "%d\n", qu( 1, 0, n-1, x, y ) );
            }
        }
    }
    return 0;
}
