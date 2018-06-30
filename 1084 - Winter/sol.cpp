#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
const int inf = 1 << 25;
const ll lim = 1e12 + 3;
#define sqr( a ) ( ( a ) * ( a ) )

struct SegmentTree {
        int tr[sz * 4];

        void reset() {
                memset( tr, -1, sizeof tr );
        }

        inline void build( int node, int b, int e ) {
                tr[node] = inf;
                if( b == e ) {
                        return;
                }
                int left = node << 1;
                int right = left | 1;
                int mid = (b + e) >> 1;
                build( left, b, mid );
                build( right, mid + 1, e );
                tr[node] = min( tr[left], tr[right] );
        }

        inline void update( int node, int b, int e, int idx, int x ) {
                if( b == e ) {
                        tr[node] = x;
                        return;
                }
                int left = node << 1;
                int right = left | 1;
                int mid = ( b + e ) >> 1;
                if( idx <= mid ) update( left, b, mid, idx, x );
                else update( right, mid + 1, e, idx, x );
                tr[node] = min( tr[left], tr[right] );
        }

        inline int query( int node, int b, int e, int l, int r ) {
                if( r < b || e < l ) return inf;
                if( b >= l && e <= r ) {
                        return tr[node];
                }

                int left = node << 1;
                int right = left | 1;
                int mid = (b + e) >> 1;

                int p1 = query( left, b, mid, l, r );
                int p2 = query( right, mid + 1, e, l, r );

                return min( p1, p2 );
        }
} tree;

int t, n, k, ans;
int last[sz];
int l[sz];

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &k );

                for( int i=0; i<n; i++ ) scanf( "%d", &l[i] );

                if( n < 3 ) ans = -1;
                else {
                        tree.build( 1, 0, n );
                        sort( l, l + n );
                        for( int i=0,j=0; i<n; i++ ) {
                                for( ; l[j] - l[i] <= 2 * k && j<n; j++ );
                                last[i] = j - 1;
                        }
                        tree.update( 1, 0, n, n, 0 );
                        for( int i=n-3; i>=0; i-- ) {
                                tree.update( 1, 0, n, i, tree.query( 1, 0, n, i + 3, last[i] + 1 ) + 1 );
                        }
                        if( tree.query( 1, 0, n, 0, 0 ) < inf ) {
                                ans = tree.query( 1, 0, n, 0, 0 );
                        }
                        else {
                                ans = -1;
                        }
                }

                printf( "Case %d: %d\n", cs, ans );
 
        }
 
        return 0;
}
