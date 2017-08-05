#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;
bool ar[21][21];
list < pair < int, int > > q;
list < int > p;
list < int > :: iterator it1;
list < pair < int, int > > :: iterator it2;
pair < int, int > h;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, n, m, ans, k, tot;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        q.clear(); p.clear();
        memset( ar, 0, sizeof ar );
        for( int i=0; i<n; i++ ) p.push_back( i );
        for( int i=0; i<m; i++ ) q.push_back( { i, -1 } );
        k = 0; ans = 0; tot = 0;
        bool fl = 0;
        while( true )  {
            k += 5;
            h = q.front();
            q.pop_front();
            fl = 0;
//            cerr << h.first << " " << h.second << " " << k << " ";
            if( ~h.second ) p.push_back( h.second );
            for( it1 = p.begin(); it1 != p.end(); ++it1 ) {
                if( ar[*it1][h.first] ) continue;
//                ans += k;
                ar[*it1][h.first] = 1;
                q.push_back( { h.first, *it1 } );
                tot++;
                p.erase( it1 );
                fl = 1;
//                cerr << *it1 << "\n";
                break;
            }
            if( !fl ) q.push_back( { h.first, -1 } );
//            if( !fl ) cerr << "-1\n";
            if( tot == n * m ) {
                while( p.size() != n && q.size() ) {
                    h = q.front();
                    q.pop_front();
                    if( ~h.second ) p.push_back( h.second );
                    k += 5;
                }
                break;
            }
        }
        printf( "Case %d: %d\n", cs, k );
    }
    return 0;
}
