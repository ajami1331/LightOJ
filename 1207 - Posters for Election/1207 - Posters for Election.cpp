#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 1;
typedef long long int ll;
struct info {
    int prop, sum;
} tree[mx * 3], vp[mx];

void update( int node, int b, int e, int i, int j, int x ){
    if( i > e || j < b ) {
        return;
    }
    if( b >= i && e <= j ) {
        tree[node].sum = x;
        tree[node].prop = x;
        return;
    }

    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    if( tree[node].prop != -1 ) {
        tree[left].sum = ( mid - b + 1 ) * tree[node].prop;
        tree[right].sum = ( e - mid ) * tree[node].prop;
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[node].prop = -1;
    }
    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

int query( int node, int b, int e, int i, int j ) {
    if( i > e || j < b ) {
        return 0;
    }
    if( b >= i and e <= j ) {
        return tree[node].sum;
    }

    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    if( tree[node].prop != -1 ) {
        tree[left].sum = ( mid - b + 1 ) * tree[node].prop;
        tree[right].sum = ( e - mid ) * tree[node].prop;
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[node].prop = -1;
    }

    int p1 = query( left, b, mid, i, j );
    int p2 = query( right, mid + 1, e, i, j );
    tree[node].sum = tree[left].sum + tree[right].sum;

    return p1 + p2;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) scanf( "%d %d", &vp[i].prop, &vp[i].sum );
        for( int i=0; i<mx*3; i++ ) tree[i].sum = 0, tree[i].prop = -1;
        update( 1, 1, n, 1, 2*n, 1 );
        ans = 0;
        for( int i=n-1, k=1; i>=0; i--, k++ ) {
            if( query( 1, 1, 2*n, vp[i].prop, vp[i].sum ) ) {
                ans++;
                update( 1, 1, 2*n, vp[i].prop, vp[i].sum, 0 );
            }
        }
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
