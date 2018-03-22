#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll sz = 1e5 + 10;
bool ar[sz];
bool fl[sz];
ll t, a, b, ans, cs;
vector < ll > primes;

void siv() {
        for( ll i=4; i<sz; i+=2 )  fl[i] = 1;
        for( ll i=3; i*i<sz; i+=2 ) {
                if( fl[i] ) continue;
                for( ll j=i*i; j<sz; j+=i ) {
                        fl[j] = 1;
                }
        }
        primes.push_back( 2 );
        for( ll i=3; i<sz; i+=2 ) if( fl[i] == 0 ) primes.push_back( i );
}

int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        siv();

        scanf( "%lld", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%lld %lld", &a, &b );

                memset( ar, 0, sizeof ar );

                ans = 0;

                for( ll i=0; i<primes.size(); i++ ) {
                        ll h = ( a / primes[i] ) + ( a % primes[i] ? 1 : 0 );
                        if( h == 1 ) h++;
                        if( h * primes[i] > b ) break;
                        for( ll j=h*primes[i]; j<=b; j+=primes[i] ) {
                                ar[j - a] = 1;
                        }
                }

                if( a == 1 ) ans = -1ll;

                for( ll i=a; i<=b; i++ ) ans += !( ar[i - a] );

                printf( "Case %lld: %lld\n", cs, ans );

        }
        return 0;
}
