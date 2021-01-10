#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LU_SERIOUS
    freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, ans, len;
    vector < int > vec;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        vec.resize( n );
        for( int i=0; i<n; i++ ) scanf( "%d", &vec[i] );
        sort( vec.begin(), vec.end() );
        ans = 0;
        for( int i=0; i<n-2; i++ ) {
            for( int j=i+1; j<n-1; j++ ) {
                len = lower_bound( vec.begin()+j+1, vec.end(), vec[i]+vec[j] ) - vec.begin();
                ans += ( len - j - 1 );
            }
        }
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}

