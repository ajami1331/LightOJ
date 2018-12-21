#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
using ull = unsigned long long;
const ll mod = 1e9 + 7;

#define sqr( a ) ( ( a ) * ( a ) )
const int inf = 1 << 28;
const int sz = 1e4 + 10;

int t, cs, n, m, p, s, d, ans;
vector < vector < pair < int, int > > > g, gt;

struct nd {
        int x, w;
        nd() {}
        nd( int a, int b ) {
                x = a;
                w = b;
        }
        bool operator < ( const nd& rhs ) const {
                return w > rhs.w;
        }
};

vector < int > dijk( vector < vector < pair < int, int > > > &G, int f ) {
        vector < int > dis( n + 1, inf );
        priority_queue < nd > PQ;
        PQ.push( nd( f, 0 ) );
        dis[f] = 0;
        while( !PQ.empty() ) {
                int u = PQ.top().x; PQ.pop();
                for( const auto &it: G[u] ) {
                        if( dis[it.first] > dis[u] + it.second ) {
                                dis[it.first] = dis[u] + it.second;
                                PQ.push( nd( it.first, dis[it.first] ) );
                        }
                }
        }
        return dis;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        for( int i=0; i<sz; i++ ) g.push_back( vector < pair < int, int > > () );

        for( int i=0; i<sz; i++ ) gt.push_back( vector < pair < int, int > > () );

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                for( int i=0; i<=n; i++ ) g[i].clear(), gt[i].clear();

                scanf( "%d %d %d %d %d", &n, &m, &s, &d, &p );

                for( int i=0; i<m; i++ ) {
                        int x, y, c;
                        scanf( "%d %d %d", &x, &y, &c );
                        g[ x ].push_back( make_pair( y, c ) );
                        gt[ y ].push_back( make_pair( x, c ) );
                }

                ans = -1;

                vector < int > d1 = dijk( g, s );

                vector < int > d2 = dijk( gt, d );

                for( int i=1; i<=n; i++ ) {
                        for( const auto &it: g[i] ) {
                                if( d1[i] + it.second + d2[it.first] <= p ) {
                                        ans = max( it.second, ans );
                                }
                        }
                }

                printf( "Case %d: %d\n", cs, ans );

        }
        
        return 0;
}