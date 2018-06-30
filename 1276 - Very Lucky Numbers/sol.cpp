#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1005;
const ll lim = 1e12 + 3;
#define sqr( a ) ( ( a ) * ( a ) )

int t, ans;
ll a, b;
vector < ll > v, l;

void gen( ll x ) {
        if( x > lim ) return;
        if( x > 0 ) l.push_back( x );
        gen( x * 10 + 4 );
        gen( x * 10 + 7 );
}

void gen( ll x, int idx ) {
        if( x > lim ) return;
        if( x > 1 ) v.push_back( x );
        for( int i=idx; i<(int)l.size(); i++ ) {
                if( lim / l[i] < x ) break;
                gen( x * l[i], i );
        }
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        gen( 0 );

        sort( l.begin(), l.end() );

        gen( 1, 0 );

        sort( v.begin(), v.end() );

        v.resize( unique( v.begin(), v.end() ) - v.begin() );

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lld %lld", &a, &b );

                ans = upper_bound( v.begin(), v.end(), b ) - lower_bound( v.begin(), v.end(), a );

                printf( "Case %d: %d\n", cs, ans );
 
        }
 
        return 0;
}
