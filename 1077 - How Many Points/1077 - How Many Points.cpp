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

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t;
    ll x1, x2, y1, y2, ans;
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        x1 = RI(); y1 = RI();
        x2 = RI(); y2 = RI();
        ans = __gcd( abs( x1 - x2 ), abs( y1 - y2 ) ) + 1;
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
