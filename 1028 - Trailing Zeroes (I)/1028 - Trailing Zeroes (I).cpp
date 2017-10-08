#include <bits/stdc++.h>
using namespace std;

long long n, ans, k;
const int sz = 1e6 + 10;
vector < long long > primes;
bitset < sz > fl;

void sieve() {
    for( int i=4; i<sz; i+=2 ) fl[i] = 1;
    for( int i=3; i*i<sz; i++ ) {
        if( fl[i] ) continue;
        for( int j=i*i; j<sz; j+=i ) {
            fl[j] = 1;
        }
    }
    primes.push_back( 2 );
    for( int i=3; i<sz; i+=2 ) if( !fl[i] ) primes.push_back( i );
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    sieve();
    int t;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%lld", &n );
        ans = 1;
        for( int i=0; i < primes.size() && primes[i] * primes[i] <= n; i++ ) {
            k = 0;
            while( n % primes[i] == 0 ) {
                n /= primes[i];
                k++;
            }
            ans *= ( k + 1 );
        }
        if( n != 1 ) ans <<= 1;
        --ans;
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
