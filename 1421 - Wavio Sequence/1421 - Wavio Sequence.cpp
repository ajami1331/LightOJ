#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int mx = 1e5 + 1;
int tree[mx*3], ar[mx], ar2[mx];

void update( int node, int b, int e, int i, int val ){
    if( i > e || i < b ){
		return;
    }

    if( i >= e && i <= b ){
		tree[node] = max( tree[node], val );
		return;
    }

    int left = node << 1;
    int right = left | 1;
	int mid = ( b + e ) >> 1;

	update( left, b, mid, i, val );
	update( right, mid+1, e, i, val );

	tree[node] = max( tree[left], tree[right] );
}

int query( int node, int b, int e, int i, int j ){
    if( i > e || j < b ){
		return 0;
    }

    if( b >= i && e <= j ){
		return tree[node];
    }

    int left = node << 1;
    int right = left | 1;
	int mid = ( b + e ) >> 1;

    int part1 = query( left, b, mid, i, j );
    int part2 = query( right, mid+1, e, i, j );

	return max( part1, part2 );
}
int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, n, k, ans;
    set < int > st;
    set < int > :: iterator it;
    map < int, int > mp;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
//while( cin >> n ) {
        k = 0;
        st.clear();
        mp.clear();
        for( int i=0; i<n; i++ ) {
            scanf( "%d", ar+i );
            ar2[n-i-1] = ar[i];
            st.insert( ar[i] );
        }
        for( it = st.begin(); it != st.end(); ++it ) {
            mp[*it] = ++k;
        }
        memset( tree, 0, sizeof tree );
        for( int i=0, pos; i<n; i++ ) {
            pos = mp[ar[i]];
            ar[i] = query( 1, 0, n, 0, pos-1 ) + 1;
            update( 1, 0, n, pos, ar[i] );
//            cerr << ar[i] << "\n";
        }
//        cerr << "ar2--\n";
        memset( tree, 0, sizeof tree );
        for( int i=0, pos; i<n; i++ ) {
            pos = mp[ar2[i]];
            ar2[i] = query( 1, 0, n, 0, pos-1 ) + 1;
            update( 1, 0, n, pos, ar2[i] );
//            cerr << ar2[i] << "\n";
        }
        ans = 0;
        for( int i=0; i<n; i++ ) {
            ans = max( ans, min( ar[i], ar2[n-i-1] ) );
        }
        printf( "Case %d: %d\n", cs, ans*2-1 );
//        cout << ans * 2 - 1 << "\n";
//        cerr << "-----------\n";
    }
    return 0;
}
