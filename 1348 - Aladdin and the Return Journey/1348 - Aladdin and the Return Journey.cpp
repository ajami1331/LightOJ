#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
 
const int sz = 3e4 + 10;
 
#define sqr( a ) ( ( a ) * ( a ) )

int t, cs, n, q;
int gn[sz];

int lg[sz];
int lvl[sz];
int table[sz][15];
int par[sz];
int tim;
int st[sz * 2], en[sz * 2];
int tr[sz * 2];
vector < int > G[sz];

void dfs( int fr, int u, int dep ) {
        lvl[u] = dep;
        par[u] = fr;
        st[u] = ++tim;
        for( int v: G[u] ) {
                if( fr == v ) continue;
                dfs( u, v, dep+1 );
        }
        en[u] = ++tim;
}

void init( int n ) {
        memset( table, -1, sizeof table );
        for( int i=0; i<n; i++ ) {
                table[i][0] = par[i];
        }
        for( int j=1; ( 1 << j ) < n; j++ ) {
                for( int i=0; i<n; i++ ) {
                        if( table[i][j-1] == -1 ) continue;
                        table[i][j] = table[ table[i][j-1] ][j-1];
                }
        }
        for( int i=0; i<15; i++ ) lg[1 << i] = i;
        for( int i=1; i<sz; i++ ) if( !lg[i] ) lg[i] = lg[i-1];
}

int query( int n, int p, int q ) {
        int log;
        if( lvl[p] < lvl[q] ) swap( p, q );
        log = lg[ lvl[ p ] ];
        for( int i=log; i>=0; i-- ) {
                if( lvl[p] - ( 1 << i ) >= lvl[q] ) {
                        p = table[ p ][ i ];
                }
        }
        if( p == q ) return p;
        for( int i=log; i>=0; i-- ) {
                if( table[ p ][ i ] != -1 && table[ p ][ i ] != table[ q ][ i ] ) {
                        p = table[ p ][ i ];
                        q = table[ q ][ i ];
                }
        }
        return par[p];
}

void upd(int x, int v) {
        for (; x < sz * 2; x += (x & -x)) {
                tr[x] += v;
        }
}

int qu(int x) {
        int ret = 0;
        for (; x > 0; x -= (x & -x)) {
                ret += tr[x];
        }
        return ret;       
}

int count_genie( int n, int p, int q ) {
        int lca = query( n, p, q );
        return qu(st[p]) + qu(st[q]) + gn[lca] - 2 * qu(st[lca]);
}

int main() {

        scanf("%d", &t);

        for (int cs = 1; cs <= t; cs++) {

                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                        scanf("%d", &gn[i]);
                }

                for (int i = 0; i < n; i++) {
                        G[i].clear();
                }

                for (int i = 1; i < n; i++) {
                        int x, y;
                        scanf("%d %d", &x, &y);
                        G[x].push_back(y);
                        G[y].push_back(x);
                }

                tim = 0;

                dfs(-1, 0, 0);

                init(n);

                memset(tr, 0, sizeof tr);

                for (int i = 0; i < n; i++) {
                        upd(st[i], +gn[i]);
                        upd(en[i], -gn[i]);
                }

                scanf("%d", &q);

                printf("Case %d:\n", cs);

                while (q--) {
                        int ty, x, y;
                        scanf("%d %d %d", &ty, &x, &y);
                        if (ty == 0) {
                                printf("%d\n", count_genie(n, x, y));
                        } else {
                                upd(st[x], +(y - gn[x]));
                                upd(en[x], -(y - gn[x]));
                                gn[x] = y;
                        }
                }
        }

        return 0;
}