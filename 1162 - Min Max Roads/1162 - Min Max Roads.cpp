#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;
const int lim = 1e5;

vector < pair < int, int > > G[sz];
int ar[sz];
int lg[sz];
int lvl[sz];
int table[sz][18];
int ans[sz][18];
int bns[sz][18];
int par[sz];
int t, n, q, cs;

void dfs( int fr, int u, int dep, int v1, int v2 ) {
        lvl[u] = dep;
        par[u] = fr;
        ans[u][0] = v1;
        bns[u][0] = v2;
        for( int i=0; i<G[u].size(); i++ ) {
                const pair < int, int >& vv = G[u][i];
                int v = vv.first;
                v1 = vv.second;
                v2 = vv.second;
                if( fr == v ) continue;
                dfs( u, v, dep+1, v1, v2 );
        }
}

int init( int n ) {
        for( int i=0; i<n; i++ ) {
                table[i][0] = par[i];
        }
        for( int j=1; ( 1 << j ) < n; j++ ) {
                for( int i=0; i<n; i++ ) {
                        if( table[i][j-1] == -1 ) continue;
                        table[i][j] = table[ table[i][j-1] ][j-1];
                        ans[i][j] =  max( ans[ table[i][j-1] ][ j-1 ], ans[i][j-1] );
                        bns[i][j] =  min( bns[ table[i][j-1] ][ j-1 ], bns[i][j-1] );
                }
        }
        for( int i=0; (1<<i) < sz;i++ ) lg[1 << i] = i;
        for( int i=1; i<sz; i++ ) if( !lg[i] ) lg[i] = lg[i-1];
}

int q1( int n, int p, int q ) {
        int ret = INT_MAX;
        int log;
        if( lvl[p] < lvl[q] ) swap( p, q );
        log = lg[ lvl[ p ] ];
        for( int i=log; i>=0; i-- ) {
                if( lvl[p] - ( 1 << i ) >= lvl[q] ) {
                        ret = min( ret, bns[p][i] );
                        p = table[ p ][ i ];
                }
        }
        if( p == q ) return ret;
        for( int i=log; i>=0; i-- ) {
                if( table[ p ][ i ] != -1 && table[ p ][ i ] != table[ q ][ i ] ) {
                        ret = min( ret, bns[p][i] );
                        ret = min( ret, bns[q][i] );
                        p = table[ p ][ i ];
                        q = table[ q ][ i ];
                }
        }
        ret = min( ret, bns[p][0] );
        ret = min( ret, bns[q][0] );
        return ret;
}

int q2( int n, int p, int q ) {
        int ret = INT_MIN;
        int log;
        if( lvl[p] < lvl[q] ) swap( p, q );
        log = lg[ lvl[ p ] ];
        for( int i=log; i>=0; i-- ) {
                if( lvl[p] - ( 1 << i ) >= lvl[q] ) {
                        ret = max( ret, ans[p][i] );
                        p = table[ p ][ i ];
                }
        }
        if( p == q ) return ret;
        for( int i=log; i>=0; i-- ) {
                if( table[ p ][ i ] != -1 && table[ p ][ i ] != table[ q ][ i ] ) {
                        ret = max( ret, ans[p][i] );
                        ret = max( ret, ans[q][i] );
                        p = table[ p ][ i ];
                        q = table[ q ][ i ];
                }
        }
        ret = max( ret, ans[p][0] );
        ret = max( ret, ans[q][0] );
        return ret;
}

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<=n; i++ ) G[i].clear();

                for( int i=1; i<n; i++ ) {
                        int x, y, w;
                        scanf( "%d %d %d", &x, &y, &w );
                        --x, --y;
                        G[x].push_back( make_pair( y, w ) );
                        G[y].push_back( make_pair( x, w ) );
                }

                memset( table, -1, sizeof table );

                memset( ans, -1, sizeof ans );

                memset( bns, 63, sizeof bns );

                dfs( -1, 0, 0, -lim, lim + 1 );

                init( n );

                scanf( "%d", &q );

                printf( "Case %d:\n", cs );

                while( q-- ) {
                        int x, y;
                        scanf( "%d %d", &x, &y );
                        --x, --y;
                        printf( "%d %d\n", q1( n, x, y ), q2( n, x, y ) );
                }

        }
        return 0;
}
