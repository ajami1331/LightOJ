#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;
long long ar[mx];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs;
    long long m, n, x, h, ans;
    cin >> t;
    for( cs=1; cs<=t; cs++ ) {
        cin >> n >> m;
        memset( ar, 0, sizeof ar );
        h = 0;
        ans = 0;
        ar[0] = 1;
        for( int i=0; i<n; i++ ) {
            cin >> x;
            h = ( h + x ) % m;
            ans += ar[ h ];
            ar[ h ]++;
        }
        cout << "Case " << cs << ": " << ans << "\n";
    }
    return 0;
}
