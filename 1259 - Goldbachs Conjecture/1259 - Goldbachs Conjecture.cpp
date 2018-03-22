#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int sz = 1e7 + 10;
int t, n, ans, cs;
vector < int > primes;
bool fl[sz];

void siv() {
        for( int i=4; i<sz; i+=2 )  fl[i] = 1;
        for( int i=3; i*i<sz; i+=2 ) {
                if( fl[i] ) continue;
                for( int j=i*i; j<sz; j+=i ) {
                        fl[j] = 1;
                }
        }
        fl[0] = 1;
        fl[1] = 1;
        primes.push_back( 2 );
        for( int i=3; i<sz; i+=2 ) if( fl[i] == 0 ) primes.push_back( i );
}

int main() {
        #ifdef CLown1331
                freopen( "in.txt", "r", stdin );
        #endif /// CLown1331

        siv();

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                ans = 0;

                for( int i=0; i<primes.size(); i++ ) {
                        int j = n - primes[i];
                        if( primes[i] > j ) break;
                        if( !fl[j] ) {
                                ans++;
                        }
                }

                printf( "Case %d: %d\n", cs, ans );

        }
        return 0;
}
