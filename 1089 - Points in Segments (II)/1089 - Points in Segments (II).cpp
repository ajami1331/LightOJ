#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;
const int tot = 5e4 + 1;
int ar[tot], x[tot], y[tot];
struct info {
    int prop, sum;
} tree[ mx * 3 ];

void check( int node, int b, int e ) {
    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    cerr << b << " " << e << ": " << tree[node].prop << "\n";

    if( b == e ) return;
    check( left, b, mid );
    check( right, mid + 1, e );
}

void update( int node, int b, int e, int i, int j, int x = 1 ) {
//    cerr << b << " " << e << " " << i << " " << j << " " << x << "\n";
    if( i > e || j < b ) {
        return;
    }
    if( b >= i && e <= j ) {
//        tree[node].sum += ( e - b + 1 ) * x;
        tree[node].prop += x;
        return;
    }

    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    update( left, b, mid, i, j, x );
    update( right, mid + 1, e, i, j, x );

//    tree[node].sum = tree[left].sum + tree[right].sum;}

int query( int node, int b, int e, int i ) {
    if( i > e || i < b ) {
        return 0;
    }
    if( b >= i and e <= i ) {
        return tree[node].prop;
    }

    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    if( i <= mid ) return query( left, b, mid, i ) + tree[node].prop;
    else return query( right, mid + 1, e, i ) + tree[node].prop;

    return tree[node].prop;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, k, q;
    set < int > st;
    map < int, int > mp;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        mp.clear();
        st.clear();
        for( int i=0; i<mx*3; i++ ) tree[i].prop = 0, tree[i].sum = 0;
        scanf( "%d %d", &n, &q );
        for( int i=0; i<n; i++ ) {
            scanf( "%d %d", &x[i], &y[i] );
            st.insert( x[i] );
            st.insert( y[i] );
        }
        printf( "Case %d:\n", cs );
        for( int i=0; i<q; i++ ) {
            scanf( "%d", &ar[i] );
            st.insert( ar[i] );
        }
        k = 0;
        for( set < int > :: iterator it = st.begin(); it != st.end(); ++it ) {
            mp[*it] = ++k;
        }
        for( int i=0; i<n; i++ ) {
            x[i] = mp[x[i]];
            y[i] = mp[y[i]];
//            cerr << x[i] << " " << y[i] << "\n";
            update( 1, 1, k, x[i], y[i] );
        }
//        check( 1, 1, k );
        for( int i=0; i<q; i++ ) {
            ar[i] = mp[ar[i]];
//            cerr << ar[i] << ": ";
            printf( "%d\n", query( 1, 1, k, ar[i] ) );
        }
    }
    return 0;
}
