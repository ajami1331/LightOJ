#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, cs, t, fl;
ll k, x;
vector < ll > v1, v2;
map < ll, bool > mp;

void rec1( int pos, ll sum ) {
    if( pos == v1.size() ) {
        mp[sum] = true;
        return;
    }
    rec1( pos+1, sum );
    rec1( pos+1, sum+v1[pos] );
    rec1( pos+1, sum+v1[pos]+v1[pos] );
}

void rec2( int pos, ll sum ) {
    if( pos == v2.size() ) {
        fl |= mp[k-sum];
        return;
    }
    rec2( pos+1, sum );
    rec2( pos+1, sum+v2[pos] );
    rec2( pos+1, sum+v2[pos]+v2[pos] );
}

int main() {
    #ifdef CLown1331
        freopen("in.txt", "r", stdin);
    #endif // CLown1331
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %lld", &n, &k );
        v1.clear();
        v2.clear();
        mp.clear();
        for( int i=0; i<n/2; i++ ) {
            scanf( "%lld", &x );
            v1.push_back( x );
        }
        for( int i=n/2; i<n; i++ ) {
            scanf( "%lld", &x );
            v2.push_back( x );
        }
        fl = 0;
        rec1( 0, 0LL );
        rec2( 0, 0LL );
        printf( "Case %d: %s\n", cs, fl ? "Yes" : "No" );
    }
    return 0;
}
