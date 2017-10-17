#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 25;
int ar[205];
int dis[205];
int cyc[205];
struct ed {
    int a, b, w;
} hand;

vector < ed > ve;

int main() {
    int t, n, m, q;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=1; i<=n; i++ ) scanf( "%d", &ar[i] );
        scanf( "%d", &m );
        ve.clear();
        for( int i=0,a,b; i<m; i++ ) {
            scanf( "%d %d", &a, &b );
            hand.a = a;
            hand.b = b;
            hand.w = ( ar[b] - ar[a] ) * ( ar[b] - ar[a] ) * ( ar[b] - ar[a] );
            ve.push_back( hand );
        }
        for( int i=0; i<=n; i++ ) {
            dis[i] = inf + inf;
            cyc[i] = 0;
        }
        dis[1] = 0;
        for( int j=1; j<n; j++ ) {
            for( int i=0; i<m; i++ ) {
                if( dis[ ve[i].b ] > dis[ ve[i].a ] + ve[i].w ) {
                    dis[ ve[i].b ] = dis[ ve[i].a ] + ve[i].w;
                }
            }
        }
        for( int j=0; j<n; j++ ) {
            for( int i=0; i<m; i++ ) {
                if( dis[ ve[i].b ] > dis[ ve[i].a ] + ve[i].w ) {
                    cyc[ ve[i].b ] = 1;
                    dis[ ve[i].b ] = -inf;
                }
            }
        }
        printf( "Case %d:\n", cs );
        scanf( "%d", &q );
        for( int i=0,b; i<q; i++ ) {
            scanf( "%d", &b );
            if( dis[b] < 3 || dis[b] >= inf || cyc[b] ) {
                printf( "?\n" );
            }
            else {
                printf( "%d\n", dis[b] );
            }
        }
    }
    return 0;
}