#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int inf = 1e9;
int n;
int dp[52][4][6];
char str[55];
string ans[4] = { "", "GOOD", "BAD", "MIXED" };

bool check( char c ) {
    return ( c =='A' || c =='E' || c =='I' || c =='O' || c == 'U' );
}

int rec( int i, int v, int c ) {
    if( v == 3 ) return 2;
    if( c == 5 ) return 2;
    if( i == n ) return 1;
    if( ~dp[i][v][c] ) return dp[i][v][c];
    int &ret = dp[i][v][c];
    ret = 0;
//    cerr << i << " " << v << " " << c << "\n";
    if( str[i] == '1' ) ret |= rec( i+1, v+1, 0 );
    if( str[i] == '0' ) ret |= rec( i+1, 0, c+1 );
    if( str[i] == '?' ) ret |= ( rec( i+1, v+1, 0 ) | rec( i+1, 0, c+1 ) );
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%s", str );
        n = strlen( str );
        for( int i=0; i<n; i++ ) {
            if( str[i] == '?' ) continue;
            str[i] = check( str[i] ) + '0';
        }
        memset( dp, -1, sizeof dp );
//        cerr << rec( 0, 0, 0 ) << "\n";
        printf( "Case %d: %s\n", cs, ans[ rec( 0, 0, 0 ) ].c_str() );
    }
    return 0;
}
