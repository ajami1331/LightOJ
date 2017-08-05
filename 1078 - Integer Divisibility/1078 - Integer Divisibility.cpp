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

typedef unsigned long long int ll;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, a, b, cnt, hand;
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        a = RI(); b = RI();
        hand = 0; cnt = 0;
        do {
            hand *= 10;
            hand += b;
            hand %= a;
            cnt++;
        } while( hand );
        printf( "Case %d: %d\n", cs, cnt );
    }
    return 0;
}
