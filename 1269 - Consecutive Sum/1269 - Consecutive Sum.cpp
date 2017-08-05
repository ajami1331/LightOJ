#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;

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

struct node {
    int en[3];
    node *next[3];
    node() {
        for( int i=0; i<3; i++ ) next[i] = NULL, en[i] = 0;
    }
    void insert( int n, int p )  {
        if( p == -1 ) return;
        int id = n & ( 1 << p ) ? 1 : 0;
        en[id]++;
        if( next[id] == NULL ) next[id] = new node();
        next[id]->insert( n, p-1 );
    }
    void remove( int n, int p )  {
        if( p == -1 ) return;
        int id = n & ( 1 << p ) ? 1 : 0;
        en[id]--;
        if( next[id] == NULL ) return;
        next[id]->remove( n, p-1 );
    }
    int srch( int n, int p )  {
        if( p == -1 ) return 0;
        int id = n & ( 1 << p ) ? 1 : 0;
        if( next[id^1] != NULL && en[id^1] ) return next[id^1]->srch( n, p-1 ) | ( 1 << p );
        if( next[id] != NULL && en[id] ) return next[id]->srch( n, p-1 );
        return 0;
    }
    int srch2( int n, int p )  {
        if( p == -1 ) return 0;
        int id = n & ( 1 << p ) ? 1 : 0;
        if( next[id] != NULL && en[id] ) return next[id]->srch2( n, p-1 );
        if( next[id^1] != NULL && en[id^1] ) return next[id^1]->srch2( n, p-1 ) | ( 1 << p );
        return 0;
    }
    void del() {
        for( int i=0; i<3; i++ ) {
            if( next[i] != NULL ) next[i]->del();
        }
        delete this;
    }
} *root;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, n, cs, h, cur, mxx, mnn;
    t = RI();
    for( cs=1; cs<=t; cs++ ) {
        n = RI();
        root = new node();
//        root->insert( 0, 31 );
        cur = 0;
        root->insert( cur, 31 );
        for( int i=0; i<n; i++ ) {
            h = RI();
            if( i == 0 ) {
                mxx = h;
                mnn= h;
            }
            cur ^= h;
            mxx = max( mxx, root->srch( cur, 31 ) );
            mnn = min( mnn, root->srch2( cur, 31 ) );
            root->insert( cur, 31 );
        }
        printf( "Case %d: %d %d\n", cs, mxx, mnn );
        root->del();
    }
    return 0;
}
