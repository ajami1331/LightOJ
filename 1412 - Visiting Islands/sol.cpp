#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1e5 + 10;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, m, q, cs;
vector < int > G[sz];
int ar[sz];
bool vis[sz];
int root, max_depth, c_size, max_c_size;

void dfs( int u, int pr, int depth ) {
        vis[u] = 1;
        c_size++;
        if( max_depth < depth ) {
                max_depth = depth;
                root = u;
        }
        for( const int& v: G[u] ) {
                if( v != pr ) {
                        dfs( v, u, depth + 1 );
                }
        }
}

struct SegmentTree {
        int tr[sz * 4];

        void reset() {
                memset( tr, -1, sizeof tr );
        }

        inline void build( int node, int b, int e ) {
                if( b == e ) {
                        tr[node] = ar[b];
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
                        tr[node] = x;
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
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<=n; i++ ) G[i].clear();

                for( int i=0; i<m; i++ ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        G[ x ].push_back( y );
                        G[ y ].push_back( x );
                }

                memset( vis, 0, sizeof vis );

                memset( ar, 0, sizeof ar );

                max_c_size = 0;

                for( int i=1; i<=n; i++ ) {
                        if( !vis[i] ) {
                                root = i;
                                max_depth = 0;
                                c_size = 0;
                                dfs( root, -1, 0 );
                                max_depth = 0;
                                c_size = 0;
                                dfs( root, -1, 0 );
                                ar[c_size] = max( ar[c_size], max_depth + 1 );
                                max_c_size = max( max_c_size, c_size );
                        }
                }

                tree.build( 1, 0, sz - 1 );

                scanf( "%d", &q );

                printf( "Case %d:\n", cs );

                while( q-- ) {
                        int k;
                        scanf( "%d", &k );
                        int v = tree.query( 1, 0, sz - 1, k, sz - 1 );
                        if( v >= k ) {
                                printf( "%d\n", k - 1 );
                        }
                        else if( k > max_c_size ) {
                                printf( "impossible\n" );
                        }
                        else {
                                printf( "%d\n", v + ( k - v ) * 2 - 1 );
                        }
                }

        }
 
        return 0;
}
