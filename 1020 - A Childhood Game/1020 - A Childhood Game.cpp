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

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n;
    string s;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        cin >> n >> s;
        n %= 3;
        printf( "Case %d: ", cs );
        if( !n ) printf( "Alice\n" );
        else if( s == "Alice" ) {
            if( n == 2 ) printf( "Alice\n" );
            else printf( "Bob\n" );
        } else printf( "Bob\n" );
    }
    return 0;
}
