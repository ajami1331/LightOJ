#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
 
const int sz = 1e7 + 10;
const ll mod = 1e9 + 7;
 
#define sqr( a ) ( ( a ) * ( a ) )
 
int t;
ll n;
bitset < sz > fl;
vector < ll > pr;
 
void pre() {
        for( int i=4; i<sz; i+=2 ) fl[i] = 1;
        for( int i=3; i*i<sz; i+=2 ) {
                if( fl[i] ) continue;
                for( int j=i*i; j<sz; j+=i ) {
                        fl[j] = 1;
                }
        }
        pr.push_back( 2 );
        for( int i=3; i<sz; i+=2 ) if( fl[i] == 0 ) pr.push_back( i );
}
 
ll ans() {
        ll ret = 1;
        ll p = 0;
        for( const ll& x: pr ) {
                if( x * x > n ) {
                        break;
                }
                p = 0;
                if( n % x == 0 ) {
                        while( n % x == 0 ) {
                                n /= x;
                                p++;
                        }
                }
                ret *= ( 2 * p + 1 );
        }
        if( n != 1 ) {
                p = 1;
                ret *= ( 2 * p + 1 );
        }
        ret = ret / 2 + ret % 2;
        return ret;
}
 
int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        pre();
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%lld", &n );
 
                printf( "Case %d: %lld\n", cs, ans() );
 
        }
 
        return 0;
}
