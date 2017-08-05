#include <stdio.h>

const int mx = 1e5 + 10;

inline int RI() {
    int ret = 0, flag = 1,ip = getchar();
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

int ar[105], h;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, n, fl;
    t = RI();
    for( cs=1; cs<=t; cs++ ) {
       n = RI();
       for( int i=0; i<n; i++ ) ar[i] = RI();
       fl = 0;
       for( int i=0; i<n; i++ ) {
            h = RI();
            h -= ar[i] + 1;
            fl ^= h;
       }
       printf( "Case %d: %s wins\n", cs, fl ? "white" : "black" );
    }
    return 0;
}

