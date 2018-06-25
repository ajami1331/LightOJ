#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
 
const int sz_m = 5762860;
const int sz = 1e8 + 10;
const ll mod = 1ll << 32;
 
#define sqr( a ) ( ( a ) * ( a ) )
 
int t;
unsigned int n;
bitset < sz > fl;
unsigned int pr[sz_m], ar[sz_m];
 
void pre() {
        for( int i=4; i<sz; i+=2 ) fl[i] = 1;
        for( int i=3; i*i<sz; i+=2 ) {
                if( fl[i] ) continue;
                for( int j=i*i; j<sz; j+=i ) {
                        fl[j] = 1;
                }
        }
        ll h = 1;
        int ind = 0;
        while( h * 2 <= sz ) {
                 h *= 2;
                 pr[ind++] = h;
        }
        for( int i=3; i<sz; i+=2 ) if( fl[i] == 0 ) {
                h = 1;
                while( h * i <= sz ) {
                        h *= i;
                        pr[ind++] = h;
                }
        }
        sort( pr, pr + sz_m );
        unsigned int hand = 1;
        ind = 0;
        h = 1;
        while( h * 2 <= sz ) {
                h *= 2;
                ind = upper_bound( pr, pr + sz_m, h ) - pr;
                ar[ind - 1] = 2;
        }
        for( int i=3; i<sz; i+=2 ) if( fl[i] == 0 ) {
                h = 1;
                while( h * i <= sz ) {
                        h *= i;
                        ind = upper_bound( pr, pr + sz_m, h ) - pr;
                        ar[ind - 1] = i;
                }
        }
        for( int i=1; i<sz_m; i++ ) ar[i] *= ar[i - 1];
}

unsigned int ans() {
        int ind = upper_bound( pr, pr + sz_m, n ) - pr;
        return ar[ind - 1];
}
 
int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        pre();
 
        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {
 
                scanf( "%u", &n );
 
                printf( "Case %d: %u\n", cs, ans() );
 
        }
 
        return 0;
}
