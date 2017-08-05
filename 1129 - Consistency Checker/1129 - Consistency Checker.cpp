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
    bool en;
    node *next[10];
    node() {
        en = 0;
        for( int i=0; i<10; i++ ) next[i] = NULL;
    }
    bool insert( string &str, int p )  {
        int id;
        if( en ) return 0;
        if( str.size() == p ) return en = 1;
        id = str[p] - '0';
        if( next[id] == NULL ) next[id] = new node();
        return next[id]->insert( str, p+1 );
    }
    void del() {
        for( int i=0; i<10; i++ ) {
            if( next[i] != NULL ) next[i]->del();
        }
        delete this;
    }
} *root;

string s[10005];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, n, fl;
    t = RI();
    for( cs=1; cs<=t; cs++ ) {
        root = new node();
        n = RI();
        fl = 1;
        for( int i=0; i<n; i++ ) {
            cin >> s[i];
        }
        sort( s, s+n );
        for( int i=0; i<n; i++ ) {
            fl = root->insert( s[i], 0 );
            if( !fl ) break;
        }
        root->del();
        printf( "Case %d: %s\n", cs, fl ? "YES" : "NO" );
    }
    return 0;
}
