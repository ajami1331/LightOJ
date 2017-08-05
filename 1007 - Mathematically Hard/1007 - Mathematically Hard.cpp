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
const ll mx = 5e6 + 1;
bitset < mx > mark;
ll phi[mx];

void pre() {
    for( ll i=2; i<mx; i++ ) {
        if( !phi[i] ) {
            phi[i] = i - 1;
            for( ll j=2*i; j<mx; j+=i ) {
                if( !phi[j] ) {
                    phi[j] = j;
                }
                phi[j] -= ( phi[j] / i );
            }
        }
    }
    for( ll i=2; i<mx; i++ ) {
        phi[i] *= phi[i];
        phi[i] += phi[i-1];
    }
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    pre();
    int t, a, b;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &a, &b );
        printf( "Case %d: %llu\n", cs, phi[b] - phi[a-1] );
    }
    return 0;
}
