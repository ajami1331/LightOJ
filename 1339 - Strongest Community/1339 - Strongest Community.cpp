#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 1e5 + 10;
const int lim = 1e5;
int t, cs;
int n, c, q;
int ar[sz];
int nxt[sz];

struct SegmentTree {
        int tr[sz * 4];

        void reset() {
                memset( tr, -1, sizeof tr );
        }

        inline void build( int node, int b, int e ) {
                if( b == e ) {
                        tr[node] = 0;
                        return;
                }
                int left = node << 1;
                int right = left | 1;
                int mid = (b + e) >> 1;
                build( left, b, mid );
                build( right, mid + 1, e );
                tr[node] = max( tr[left], tr[right] );
        }

        inline void update( int node, int b, int e, int idx, int x ) {
                if( b == e ) {
                        tr[node] += x;
                        return;
                }
                int left = node << 1;
                int right = left | 1;
                int mid = ( b + e ) >> 1;
                if( idx <= mid ) update( left, b, mid, idx, x );
                else update( right, mid + 1, e, idx, x );
                tr[node] = max( tr[left], tr[right] );
        }

        inline int query( int node, int b, int e, int l, int r ) {
                if( r < b || e < l ) return -1;
                if( b >= l && e <= r ) {
                        return tr[node];
                }

                int left = node << 1;
                int right = left | 1;
                int mid = (b + e) >> 1;

                int p1 = query( left, b, mid, l, r );
                int p2 = query( right, mid + 1, e, l, r );

                return max( p1, p2 );
        }
};

SegmentTree tree;

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d %d", &n, &c, &q );

                for( int i=0; i<n; i++ ) scanf( "%d", &ar[i] );

                tree.build( 1, 0, n );

                int pre = -1, cnt = 0;

                ar[n] = -1;

                for( int i=n-1; i>=0; i-- ) {
                        if( ar[i] == ar[i + 1] ) nxt[i] = nxt[i + 1];
                        else nxt[i] = i;
                }

                for( int i=0; i<n; i++ ) {
                        if( pre == ar[i] ) {
                                cnt++;
                        }
                        else {
                                pre = ar[i];
                                cnt = 1;
                        }
                        tree.update( 1, 0, n, i, cnt );
                }

                printf( "Case %d:\n", cs );

                for( int i=0; i<q; i++ ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        --x, --y;
                        if( ar[x] == ar[y] ) printf( "%d\n", y - x + 1 );
                        else printf( "%d\n", max( tree.query( 1, 0, n, nxt[x] + 1, y ), nxt[x] - x + 1 ) );
                }
        }

        return 0;
}
