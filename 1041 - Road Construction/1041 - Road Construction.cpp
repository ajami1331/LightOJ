#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, cost;
    bool operator < (const edge& other) const{
        if( other.cost == this->cost ) {
        if( other.u == this->u ) {
            return other.v > this->v;
        } else {
            return other.u > this->u;
        }
        } else {
            return other.cost > this->cost;
        }
    }
};

set < int > st;
map < string, int > city;
vector< edge > edges;
vector < int > par, cnt, rnk;
int N;

void init( int n ) {
    N = n+1;
    par.resize( N );
    cnt.resize( N );
    rnk.resize( N );
}

void add_edge( int u, int v, int c ) {
    edges.push_back( { u, v, c } );
}

void make_set() {
    for(int i=0; i<N; i++) {
        par[i] = i;
        cnt[i] = 1;
        rnk[i] = 0;
    }
}

int find_rep( int x ) {
    if(x != par[ x ]) {
        par[ x ] = find_rep( par[ x ] );
    }
    return par[ x ];
}

int kruskal() {
    int ret = 0;
    make_set();
    sort( edges.begin(), edges.end() );
//    cout << "Case " << ++cs << ":\n";
    edge e;
    for( int i=0; i<edges.size(); i++ ) {
        e = edges[i];
        int u = e.u;
        int v = e.v;
        if( ( u = find_rep( u ) ) != ( v = find_rep( v ) ) ) {
            if( rnk[ u ] < rnk[ v ] ) {
                cnt[ v ] += cnt[ u ];
                par[ u ] = par[ v ];
            } else {
                rnk[ u ] = max( rnk[ u ], rnk[ v ] + 1 );
                cnt[ u ] += cnt[ v ];
                par[ v ] = par[ u ];
            }
//            cout << city[ e.u ] << "-" << city[ e.v ] << " " << e.cost << "\n";
            ret += e.cost;
        }
    }
    return ret;
}

bool check() {
    st.clear();
    for( int i=1; i<N; i++ ) {
        st.insert( find_rep( i ) );
    }
    return st.size() == 1;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, n, m, w, k, ans;
    string x, y;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &m );
        city.clear();
        edges.clear();
        k = 0;
        while( m-- ) {
            cin >> x >> y >> w;
            if( !city[x] ) {
                city[x] = ++k;
            }
            if( !city[y] ) {
                city[y] = ++k;
            }
            edges.push_back( { city[x], city[y], w } );
        }
        init( n = city.size() );
        ans = kruskal();
        if( check() )
            printf( "Case %d: %d\n", cs, ans );
        else
            printf( "Case %d: Impossible\n", cs );
    }
    return 0;
}
