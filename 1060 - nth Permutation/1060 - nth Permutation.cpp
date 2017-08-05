#include <bits/stdc++.h>
using namespace std;

long long fac[26];
long long pos, n;
int freq[26];

void init() {
    fac[0] = 1;
    for( int i=1; i<26; i++ ) fac[i] = fac[i-1] * i;
}

long long koita( int n ) {
    long long ret = fac[n];
    for( int i=0; i<26; i++ ) ret /= fac[ freq[i] ];
    return ret;
}

void solve( int sz ) {
    long long upto, now;
    bool found;
    while( sz ) {
        upto = 0;
        found = 0;
        for( int i=0; i<26 && !found; i++ ) {
            if( freq[i] == 0 ) continue;
            freq[i]--;
            now = koita( sz-1 );
            if( now + upto >= n ) {
                n -= upto;
                sz--;
                putchar( 'a' + i );
                found = 1;
            } else {
                freq[i]++;
                upto += now;
            }
        }
        if( !found ) break;
    }
    putchar( '\n' );
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, cs;
    string s;
    cin >> t;
    init();
    for( cs=1; cs<=t; cs++ ) {
        cin >> s >> n;
        memset( freq, 0, sizeof freq );
        for( int i=0; i<s.size(); i++ ) freq[ s[i] - 'a' ]++;
        pos = koita( s.size() );
        printf( "Case %d: ", cs );
        if( pos < n ) printf( "Impossible\n" );
        else solve( s.size() );
    }
    return 0;
}
