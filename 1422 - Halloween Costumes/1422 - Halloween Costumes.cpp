#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;
int dp[101][101];
vector < int > ar;
const int inf = 1e9;

int rec( int i, int j ) {
    if( i >= j ) return 0;
    if( ~dp[i][j] ) return dp[i][j];
    int &ret = dp[i][j];
    ret = rec( i+1, j ) + 1;
    for( int k=i+1; k<=j; k++ ) {
        if( ar[k] == ar[i] ) {
            ret = min( ret, 1 + rec( i+1, k-1 ) + rec( k, j ) );
        }
    }
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
        scanf( "%d", &n );
//while( cin >> n ) {
        ar.resize( n );
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &ar[i] );
        }
        ar.resize( unique( ar.begin(), ar.end() ) -  ar.begin() );
        memset( dp, -1, sizeof dp );
        printf( "Case %d: %d\n", cs, rec( 0, ar.size() - 1 ) + 1 );
    }
    return 0;
}
