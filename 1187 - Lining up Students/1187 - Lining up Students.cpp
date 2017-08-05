#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;
int tree[mx], ar[mx], tr[mx], n;

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

void update( int x, int v ) {
    for( ; x<=n; x+=(x&-x) ) {
        tree[x] += v;
    }
}

int qu( int x ) {
    int ret = 0;
    for( ; x; x-=(x&-x) ) {
        ret += tree[x];
    }
    return ret;
}

int get( int x ) {
    int lo = 1, hi = n, mid;
    while( hi - lo > 4 ) {
        mid = ( hi + lo ) >> 1;
        if( qu( mid ) < x ) lo = mid + 1;
        else hi = mid;
    }
    for( ; lo<=hi; lo++ ) {
        if( qu( lo ) == x ) return lo;
    }
    return -1;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs, h;
    t = RI();
    for( cs=1; cs<=t; cs++ ) {
        n = RI();
        memset( tree, 0, sizeof tree );
        for( int i=1; i<=n; i++ ) {
            ar[i] = RI();
            update( i, 1 );
        }
        for( int i=n; i; i-- ) {
            h = i - ar[i];
//            cerr << h << " ";
            h = get( h );
//            cerr << h << " \n";
            tr[i] = h;
            update( h, -1 );
        }
//        for( int i=1; i<=n; i++ ) cerr << tr[i] << " \n"[ i==n ];
        printf( "Case %d: %d\n", cs, tr[1] );
    }
    return 0;
}
