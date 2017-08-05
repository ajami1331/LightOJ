#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    ull n, k, ans;
    cin >> t;
    for( cs=1; cs<=t; cs++ ) {
        cin >> n >> k;
        if( n*n >= k ) {
            ans = 1;
            for( ull kk=1; kk<=k; kk++ ) {
                ans = ans * n*n/kk;
                --n;
            }
        } else ans = 0;
        cout << "Case " << cs << ": ";
        cout << ans << "\n";
    }
    return 0;
}
