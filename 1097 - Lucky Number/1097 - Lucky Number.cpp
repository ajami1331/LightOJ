#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e5 + 1;
const int sz=1429450;
int tree[sz];

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
    int lo = 0, hi = sz, mid;
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
    vector < int > v;
    for( int i=1; i<=sz; i+=2 ) update( i, 1 );
    int x, id = 2, ot = 0;
    while( query( sz ) > mx ) {
        x = calc( id );
        for( int i=x; i<=sz; i+=x ) {
            v.push_back( calc( i ) );
        }
        ot += v.size();
        for( int i=0; i<v.size(); i++ ) update( v[i], -1 );
        v.clear();
        id++;
    }
    v.clear();
    v.push_back( 0 );
    for( int i=1; i<mx; i++ ) {
        v.push_back( calc( i ) );
    }
    int t, n;
//    scanf( "%d", &t );
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        n = RI();
//        scanf( "%d", &n );
        printf( "Case %d: %d\n", cs, v[n] );
    }
    return 0;
}
