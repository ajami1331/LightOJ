#include <bits/stdc++.h>
using namespace std;

char s[255];

int main() {
#ifdef LU_SERIOUS
    freopen( "in.txt", "r", stdin );
#endif // LU_SERIOUS
    int tc;
    long long int b, m;
    scanf("%d", &tc);
    for(int cs=1; cs<=tc; cs++) {
        scanf("%s %lld", s, &b);
        m = 0;
        for(int i = s[0] == '-'; s[i]!='\0'; i++) {
            m *= 10;
            m += s[i] - '0';
            m %= b;
        }
        printf("Case %d: ", cs);
        if( m ) {
            printf("not divisible\n");
        } else {
            printf("divisible\n");
        }
    }
    return 0;
}

