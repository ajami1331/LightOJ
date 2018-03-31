#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int sz = 1e6 + 10;
int t, n, cs;
ll ar[32], w;
vector < ll > A, B, v1, v2;
int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d %lld", &n, &w );

                for( int i=0; i<n; i++ ) scanf( "%lld", &ar[i] );

                v1.clear();

                v2.clear();

                A.clear();

                B.clear();

                for( int i=0; i<n/2; i++ ) v1.push_back( ar[i] );

                for( int i=n/2; i<n; i++ ) v2.push_back( ar[i] );

                int ch;

                ch = v1.size();

                ch = 1 << ch;

                for( int mask=0; mask<ch; mask++ ) {
                        ll sm = 0;
                        for( int i=0; i<v1.size(); i++ ) {
                                if( mask & ( 1 << i ) ) {
                                        sm += v1[i];
                                }
                        }
                        A.push_back( sm );
                }

                ch = v2.size();

                ch = 1 << ch;

                for( int mask=0; mask<ch; mask++ ) {
                        ll sm = 0;
                        for( int i=0; i<v2.size(); i++ ) {
                                if( mask & ( 1 << i ) ) {
                                        sm += v2[i];
                                }
                        }
                        B.push_back( sm );
                }

                sort( B.begin(), B.end() );

                ll ans = 0;

                for( int i=0; i<A.size(); i++ ) {
                        ans += upper_bound( B.begin(), B.end(), w - A[i] ) - B.begin();
                }

                printf( "Case %d: %lld\n", cs, ans );
        }

        return 0;
}
