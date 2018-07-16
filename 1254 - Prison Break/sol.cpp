#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1 << 23;
const int pr_sz = 1e6 + 10;
const double eps = 1e-9;
const int mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )

int t, n, m, q;
int ar[105];
vector < pair < int, int > > G[105];
int dis[105][105];

struct nd {
        int x, w, c;
        nd() {}
        nd( int _x, int _w, int _c ) : x(_x), w(_w), c(_c) {}
        bool operator < ( const nd& ot ) const {
                if( w == ot.w ) return c < ot.c;
                return w > ot.w;
        }
};

int dijk( int c, int s, int t ) {
        priority_queue < nd > PQ;
        int inf;
        memset( dis, 63, sizeof dis );
        inf = dis[0][0];
        dis[s][0] = 0;
        PQ.push( nd( s, 0, 0 ) );
        nd h;
        while( !PQ.empty() ) {
                h = PQ.top(); PQ.pop();
                if( h.x == t ) break;
                for( const auto it: G[h.x] ) {
                        for( int i=max(0,it.second-h.c); i+h.c<=c; i++ ) {
                                if( dis[it.first][i+h.c-it.second] > h.w + ( i * ar[h.x] ) ) {
                                        dis[it.first][i+h.c-it.second] = h.w + ( i * ar[h.x] );
                                        PQ.push( nd( it.first, h.w + ( i * ar[h.x] ), i+h.c-it.second ) );
                                }
                        }
                }
        }
        int ret = inf;
        for( int i=0; i<=c; i++ ) {
                ret = min( ret, dis[t][i] );
        }
        return ret == inf ? -1 : ret;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d %d", &n, &m );

                for( int i=0; i<n; i++ ) G[i].clear(), scanf( "%d", &ar[i] );

                while( m-- ) {
                        int x, y, w;
                        scanf( "%d %d %d", &x, &y, &w );
                        G[ x ].push_back( make_pair( y, w ) );
                        G[ y ].push_back( make_pair( x, w ) );
                }

                scanf( "%d", &q );

                printf( "Case %d:\n", cs );

                while( q-- ) {
                        int c, s, t;
                        scanf( "%d %d %d", &c, &s, &t );
                        int ans = dijk( c, s, t );
                        if( ans == -1 ) printf( "impossible\n" );
                        else printf( "%d\n", ans );
                }

        }

        return 0;
}
