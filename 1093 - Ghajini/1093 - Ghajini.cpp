#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 1e5 + 1;
int ar[mx];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, d, ty, x, y, v, ans;
    multiset < int > st;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &d );
        ans = 0;
        st.clear();
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &ar[i] );
            st.insert( ar[i] );
            if( st.size() > d ) {
                st.erase( st.find( ar[i-d] ) );
            }
            ans = max( ans, ( *st.rbegin() - *st.begin() ) );
        }
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
