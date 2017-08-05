#include <bits/stdc++.h>
using namespace std;

//#define gc getchar
#define gc getchar_unlocked
const int inf = 1e9;
const int mx = 1e5 + 10;
int t, cs, n, m, x, y, cmp;
int cnt[mx];
bitset < mx > vis;
vector < int > G[mx];
long long ans;

inline void get_num(int& num)
{
    num = 0;
    char c = gc();
    int flag = 0;
    while(!((c>='0' & c<='9') || c == '-'))
        c=gc();
    if(c == '-')
    {
        flag = 1;
        c=gc();
    }
    while(c>='0' && c<='9')
    {
        num = (num<<1)+(num<<3)+c-'0';
        c=gc();
    }
    if(flag==1)
        num=0-num;
}

int dfs( int u ) {
    int v;
    vis[u] = 1;
    cnt[u] = 1;
//    nds[u] = cmp;
    long long a = 0;
    for( int i=0; i<G[u].size(); i++ ) {
        v = G[u][i];
        if( !vis[v] ) {
            cnt[u] += dfs( v );
            ans += ( a * cnt[v] );
            a += cnt[v];
        }
    }
//    cerr << u << ": ";
//    for( int i=0; i<G[u].size(); i++ ) {
//        for( int j=i+1; j<G[u].size(); j++ ) {
//            if( i == j ) continue;
//            a = cnt[ G[ u ][ i ] ] ;
//            b = cnt[ G[ u ][ j ] ] ;
//            ans += a * b;
////            cerr << G[ u ][ i ] << " " << G[ u ][ j ] << ", " ;
//        }
//    }
//    cerr << "\n";
    return cnt[u];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    get_num( t );
    cs = 1;
    while( cs <= t ) {
        get_num( n );
        for( int i=0; i<=n; i++ ) {
            G[i].clear();
        }
        for( int i=0; i<n-1; i++ ) {
            get_num( x );
            get_num( y );
            G[x].push_back( y );
        }
        vis.reset();
        memset( cnt, 0, sizeof cnt );
//        memset( nds, 0, sizeof nds );;
        ans = 0;
        dfs( 1 );
        printf( "Case %d: %d %lld\n", cs, n-1, ans );
        cs++;
    }
}
