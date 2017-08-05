#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, p, l, q;
    set< int > st;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &p, &l );
        printf( "Case %d:", cs );
        q = p-l;
        if( q <= l ) printf( " impossible\n" );
        else {
            st.clear();
            for( long long i=1; i*i<=q; i++ ) {
                if( q % i == 0 ) {
                    st.insert( i );
                    st.insert( q / i );
                }
            }
            for( set <int> :: iterator it=st.begin(); it!=st.end(); ++it ) {
                if( *it > l ) printf( " %d", *it );
            }
            printf( "\n" );
        }
    }
    return 0;
}

