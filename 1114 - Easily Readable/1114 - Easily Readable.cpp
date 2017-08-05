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
    bool en = 0;
    int cnt = 0;
    int next[52];
} tree[mx];

int state;

void insert( string s ) {
    int id, cur = 0;
    for( int i=0; i<s.size(); i++ ) {
        if( isupper( s[i] ) ) id = s[i] - 'A' + 26;
        else id = s[i] - 'a';
        if( tree[cur].next[id] == -1 ) {
            tree[cur].next[id] = ++state;
            memset( tree[state].next, -1, sizeof tree[state].next );
            tree[state].en = 0;
            tree[state].cnt = 0;
        }
        cur = tree[cur].next[id];
    }
    tree[cur].cnt++;
    tree[cur].en = 1;
}

int koita( string s ) {
    int id, cur = 0;
    for( int i=0; i<s.size(); i++ ) {
        if( isupper( s[i] ) ) id = s[i] - 'A' + 26;
        else id = s[i] - 'a';
        cur = tree[cur].next[id];
        if( cur == -1 ) return 0;
    }
    return tree[cur].cnt;
}

string s;
char sss[mx];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, n, ans;
    cin >> t;
    for( cs=1; cs<=t; cs++ ) {
        state = 0;
        memset( tree[state].next, -1, sizeof tree[state].next );
        tree[state].en = 0;
        tree[state].cnt = 0;
        cin >> n;
        cin.ignore();
        for( int i=0; i<n; i++ ) {
            gets( sss );
            s = sss;
            if( s.size() > 2 ) sort( s.begin()+1, s.end()-1 );
            insert( s );
//            mp[ s ]++;
        }
        cin >> n;
        cin.ignore();
        stringstream ss;
        printf( "Case %d:\n", cs );
        for( int i=0; i<n; i++ ) {
            ans = 1;
            gets( sss );
            ss << sss;
            while( ss >> s ) {
                if( s.size() > 2 ) sort( s.begin()+1, s.end()-1 );
                ans *= koita( s );
//                ans *= mp[ s ];
            }
            ss.clear();
            printf( "%d\n", ans );
        }
    }
    return 0;
}
