#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1 << 17;
const double eps = 1e-9;

#define sqr( a ) ( ( a ) * ( a ) )

int t, ans;
ll n;
bitset < sz > fl;
vector < int > pr;
int neg;

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

int lsb( int x ) {
        int i;
        for( i=0; !(x&(1<<i)); i++ );
        return i;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        pre();

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%lld", &n );

                ans = 0;

                neg = n < 0;

                n = abs( n );

                for( const int& i: pr ) {
                        if( i * i > n ) break;
                        if( n % i == 0 ) {
                                int cnt = 0;
                                while( n % i == 0 ) {
                                        n /= i;
                                        cnt++;
                                }
                                ans = __gcd( cnt, ans );
                        }
                }

                if( n != 1 ) ans = 1;

                if( neg ) ans /= ( 1 << lsb( ans ) );

                printf( "Case %d: %d\n", cs, ans );

        }
 
        return 0;
}
