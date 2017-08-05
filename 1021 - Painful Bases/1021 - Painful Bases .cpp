#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int t, b, k, cs, n;
int ar[17];
ll dp[1<<16+1][20];
int vv[1<<16+1][20];

bool check( int mask, int pos ) {
    return mask & ( 1 << pos );
}

int Set( int mask, int pos ) {
    return mask | ( 1 << pos );
}

ll rec( int mask, int sum ) {
    if( mask == ( 1 << n ) - 1 ) return sum == 0;
    if( vv[mask][sum] == cs ) return dp[mask][sum];
    vv[mask][sum] = cs;
    ll &ret = dp[mask][sum];
    ret = 0;
    for( int i=0; i<n; i++ ) {
        if( !check( mask, i ) ) {
            ret += rec( Set( mask, i ), ( ar[i] + b * sum ) % k );
        }
    }
    return ret;
}


int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    char str[17];
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %s", &b, &k, str );
        n = strlen( str );
        for( int i=0; i<n; i++ ) {
            if( str[i] >= 'A' )
                ar[i] =  str[i] - 'A' + 10;
            else ar[i] =  str[i] - '0';
        }
        printf( "Case %d: %lld\n", cs, rec( 0, 0 ) );
    }
    return 0;
}

