#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

inline ll RI() {
    ll  ret = 0, flag = 1,ip = getchar();
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

int t, n, k, ans, sm;
int ar[1001];

bool check( int mid ) {
    int h = 0, cn = 0;
    for( int i=0; i<=n; i++ ) {
        if( ar[i] > mid ) return false;
        if( h + ar[i] <= mid ) h += ar[i];
        else h = 0, cn++, i--;
    }
//    if( h ) cn++;
    return cn <= k;
}

int bsearch() {
    int lo = 0, hi = sm, mid;
    while( ( hi - lo ) > 4 ) {
        mid = ( lo + hi ) / 2;
        if( check( mid ) ) hi = mid - 1;
        else lo = mid;
    }
    for( ; lo <= hi; lo++ ) {
        if( check( lo ) ) break;
    }
    return lo;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        n = RI(); k = RI(); sm = 0;
        for( int i=0; i<=n; i++ ) ar[i] = RI(), sm += ar[i];
        ans = bsearch();
        printf( "Case %d: %d\n", cs, ans );
        int h = 0, cn = 0;
        for( int i=0; i<=n; i++ ) {
            if( h + ar[i] > ans ) {
                printf( "%d\n", h );
                h = 0;
                i--;
                cn++;
            } else if( h + ar[i] == ans ) {
                printf( "%d\n", h + ar[i] );
                h = 0;
                cn++;
            } else if( n - i == k - cn ) { // same same baki
                printf( "%d\n", h + ar[i] );
                h = 0;
                cn++;
            } else h += ar[i];
        }
    }
    return 0;
}
