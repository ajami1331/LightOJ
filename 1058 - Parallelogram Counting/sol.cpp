#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e3 + 10;
const ll mod = 1e9 + 7;

int ar[sz], br[sz], n, a, b;
ll ans, h;

vector < pair < int, int > > v;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                ans = 0;

                v.clear();

                for( int i=0; i<n; i++ ) {
                        scanf( "%d %d", &ar[i], &br[i] );
                }

                for( int i=0; i<n; i++ ) {
                        for( int j=i+1; j<n; j++ ) {
                                a = ar[i] + ar[j];
                                b = br[i] + br[j];
                                v.push_back( make_pair( a, b ) );
                        }
                }

                sort( v.begin(), v.end() );

                ans = 0;

                for( vector< pair< int, int > >::iterator i = v.begin(); i != v.end(); ) {
                        vector< pair< int, int > >::iterator j = i;
                        h = 0;
                        while( i->first == j->first && i->second == j->second ) {
                                h++;
                                ++j;
                        }
                        i = j;
                        ans += ( h * ( h - 1 ) ) / 2;
                }

                printf( "Case %d: %lld\n", cs, ans );

        }

        return 0;
}