#include <bits/stdc++.h>
using namespace std;

string str[2];

int rev( int n ) {
    int ret = 0;
    while( n ) {
        ret *= 10;
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
#ifdef LU_SERIOUS
    freopen( "in.txt", "r", stdin );
#endif // LU_SERIOUS
    str[0] = "No";
    str[1] = "Yes";
    int tc, d;
    scanf("%d", &tc);
    for(int cs=1; cs<=tc; cs++) {
        scanf("%d", &d);
        printf("Case %d: %s\n", cs, str[ d == rev( d ) ].c_str() );
    }
    return 0;
}

