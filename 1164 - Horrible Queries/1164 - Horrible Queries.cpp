#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e5 + 1;
const int mxx = mx*3;
const int inf = 2e9;

struct info {
    ll prop, sum;
} tree[mx * 3];

void update( int node, int b, int e, int i, int j, ll x ){
    if( i > e || j < b ) {
        return;
    }
    if( b >= i && e <= j ) {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

ll query( int node, int b, int e, int i, int j, ll carry = 0 ) {
    if( i > e || j < b ) {
        return 0;
    }
    if( b >= i and e <= j ) {
        return tree[node].sum + carry * (e - b + 1);
    }

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    ll p1 = query( Left, b, mid, i, j, carry + tree[node].prop );
    ll p2 = query( Right, mid + 1, e, i, j, carry + tree[node].prop );

    return p1 + p2;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, m, ty, x, y, v;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        for( int i=0; i<mxx; i++ ) tree[i].sum = 0, tree[i].prop = 0;
        printf( "Case %d:\n", cs );
        while( m-- ) {
            scanf( "%d", &ty );
            if( ty == 0 ) {
                scanf( "%d %d %d", &x, &y, &v );
                update( 1, 0, n-1, x, y, v );
            } else {
                scanf( "%d %d", &x, &y );
                printf( "%lld\n", query( 1, 0, n-1, x, y ) );
            }
        }
    }
    return 0;
}
