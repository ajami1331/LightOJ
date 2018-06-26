#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
using ull = unsigned long long;

const int sz = 1e7 + 10;
const ll mod = 1000;
#define sqr( a ) ( ( a ) * ( a ) )
 
vector < ll > pr;
bitset < sz > fl;

int t;
ll n;

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

ll solve() {
        ll ret = 1, cnt;
        for( const ll& x: pr ) {
                if( x * x > n )  break;
                cnt = 0;
                if( n % x == 0 ) {
                        while( n % x == 0 ) {
                                n /= x;
                                cnt++;
                        }
                }
                if( x != 2 ) {
                        ret *= ( cnt + 1 );
                }
        }
        if( n > 2 ) {
                ret *= 2;
        }
        return ret - 1;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        pre();

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%lld", &n );

                printf( "Case %d: %lld\n", cs, solve() );
        }
 
        return 0;
}
