#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;
int d[501], ar[501][501];
bool mark[501][501];
vector < int > kip[501];
vector < pair < int, int > > G[501];

struct compare{
    bool operator()( pair < int, int > a, pair < int, int > b ) {
        return a.first > b.first;
    }

};

void dijkstra( int src ) {
    memset( d, 63, sizeof d );
    priority_queue < pair < int, int >, vector < pair < int, int > >, compare >  pq;
    pq.push( { 0, src } );
    d[src] = 0;
    int u, v, w;
    while( !pq.empty() ) {
        u = pq.top().second;
        pq.pop();
        for( int i=0; i<G[u].size(); i++ ) {
            v = G[u][i].first;
            w = G[u][i].second;
            if( max( d[u], w ) < d[v] ) {
                d[v] = max( d[u], w );
                pq.push( { d[v], v } );
            }
        }
    }
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, n, m, x, y, w, src;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        memset( ar, 63, sizeof ar );
        memset( mark, 0, sizeof mark );
        scanf( "%d %d", &n, &m );
        for( int i=0; i<n; i++ ) {
            G[i].clear();
            kip[i].clear();
        }
        while( m-- ) {
            scanf( "%d %d %d", &x, &y, &w );
            if( !mark[x][y] ) {
                mark[x][y] = 1;
                kip[x].push_back( y );
            }
            if( !mark[y][x] ) {
                mark[y][x] = 1;
                kip[y].push_back( x );
            }
            ar[x][y] = min( ar[x][y], w );
            ar[y][x] = min( ar[y][x], w );
        }
        for( int i=0; i<n; i++ ) {
//            cerr <<  i << ": ";
            for( int j=0; j<kip[i].size(); j++ ) {
//                cerr << *it << ", ";
                G[i].push_back( { kip[i][j], ar[i][ kip[i][j] ] } );
            }
//            cerr << "\n";
        }
//        for( int i=0; i<n; i++ ) {
//            printf( "%d: ", i );
//            for( int j=0; j<G[i].size(); j++ ) {
//                printf( "{ %d, %d }, ", G[i][j].first, G[i][j].second );
//            }
//            printf("\n");
//        }
        scanf( "%d", &src );
        dijkstra( src );
        printf( "Case %d:\n", cs );
        for( int i=0; i<n; i++ ) {
            if( d[i] >= inf ) printf( "Impossible\n" );
            else printf( "%d\n", d[i] );
        }
    }
    return 0;
}
