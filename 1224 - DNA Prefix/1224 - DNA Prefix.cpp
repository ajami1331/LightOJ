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

int ans;

struct node {
    bool en;
    int cn;
    node *next[4];
    node() {
        en = 0;
        cn = 0;
        for( int i=0; i<4; i++ ) next[i] = NULL;
    }
    void insert( string &str, int p )  {
        int id;
        cn++;
        ans = max( ans, cn * p );
        if( str.size() == p ) {
            en = 1;
            return;
        }
        if( str[p] == 'A' ) id = 0;
        if( str[p] == 'C' ) id = 1;
        if( str[p] == 'G' ) id = 2;
        if( str[p] == 'T' ) id = 3;
        if( next[id] == NULL ) next[id] = new node();
        next[id]->insert( str, p+1 );
    }
    void del() {
        for( int i=0; i<4; i++ ) {
            if( next[i] != NULL ) next[i]->del();
        }
        delete this;
    }
} *root;

string s;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, n;
    t = RI();
    for( cs=1; cs<=t; cs++ ) {
        root = new node();

        n = RI();
        ans = 0;
        for( int i=0; i<n; i++ ) {
            cin >> s;
            root->insert( s, 0 );
        }

        root->del();
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
