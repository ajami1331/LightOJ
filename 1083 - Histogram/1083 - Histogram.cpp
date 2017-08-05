#include <bits/stdc++.h>
using namespace std;

inline int RI() {
    int  ret = 0, flag = 1,ip = getchar();
    for(; ip < 48 || ip > 57; ip = getchar()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

typedef long long int ll;
const int mx = 3e4 + 1;
int t, n;
ll ar[mx], tree[mx*3];

void build( int node, int b, int e ) {
    if( b == e ) {
        tree[node] = b;
        return;
    }
    int mid = ( b + e ) >> 1;
    int left = node << 1;
    int right = left | 1;
    build( left, b, mid );
    build( right, mid+1, e );
    if( ar[ tree[left] ] < ar[ tree[right] ] ) {
        tree[node] = tree[left];
    } else tree[node] = tree[right];
}

ll qu( int node, int b, int e, int i, int j ) {
    if( i > e || j < b ) return -1;
    if( b >= i && e <= j ) return tree[node];
    int mid = ( b + e ) >> 1;
    int left = node << 1;
    int right = left | 1;
    int p1, p2;
    p1 = qu( left, b, mid, i, j );
    p2 = qu( right, mid + 1, e, i, j );
    if( p1 == -1 ) return p2;
    if( p2 == -1 ) return p1;
    if( ar[p1] < ar[p2] ) return p1;
    return p2;
}

ll solve( int b, int e ) {
//    cerr << b << " " << e << "\n";
    if( b > e ) return 0;
    if( b == e ) return ar[b];
    int mn = qu( 1, 0, n-1, b, e );
    ll ans = max( solve( b, mn-1 ), solve( mn+1, e ) );
    ans = max( ans, ( e - b + 1 ) * ar[mn] );
    return ans;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        n = RI();
        for( int i=0; i<n; i++ ) ar[i] = RI();
        build( 1, 0, n-1 );
        cerr << "build\n";
        printf( "Case %d: %lld\n", cs, solve( 0, n-1 ) );
    }
    return 0;
}
