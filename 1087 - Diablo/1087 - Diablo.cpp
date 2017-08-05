#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int sz = 1e5 + 1 + 5e4;
int tree[sz];
int v[sz];
int t, n, q, x, tot;
char c;

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
    for( ; x <= sz ; x+=(x&-x) ) tree[x] += v;
}

int query( int x ) {
    int ret = 0;
    for( ; x ; x-=(x&-x) ) ret += tree[x];
    return ret;
}

int calc( int x ) {
    int lo = 0, hi = n, mid;
    while( ( hi - lo ) >= 4 ) {
        mid = ( lo + hi ) >> 1;
        if( query( mid ) >= x ) hi = mid;
        else lo = mid;
    }
    while( lo <= hi ) {
        if( query( lo ) == x ) return lo;
        lo++;
    }
    return lo;
}
int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
//    scanf( "%d", &t );
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        memset( tree, 0, sizeof tree );
        n = RI();
        q = RI();
        for( int i=1; i<=n; i++ ) {
            x = RI();
            v[i] = x;
            update( i, 1 );
        }
//        scanf( "%d", &n );
        printf( "Case %d:\n", cs );
        while( q-- ) {
//            scanf( "%c %d\n", &c, &x );
            c = getchar();
            getchar();
            x = RI();
//            getchar();
//            cerr << c << " " << x << "\n";
            if( c == 'c' ) {
                if( ( x = calc( x ) ) > n ) {
                    printf( "none\n" );
                    continue;
                }
                printf( "%d\n", v[x] );
                update( x, -1 );
            } else {
                v[++n] = x;
                update( n, 1 );
            }
        }
    }
    return 0;
}
