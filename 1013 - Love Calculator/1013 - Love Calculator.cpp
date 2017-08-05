#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
ull lc[31][31], dp[31][31][31];
string a, b;

ull lcs( int i, int j ) {
    if( i == a.size() or j == b.size() ) return 0;
    if( ~lc[i][j] ) return lc[i][j];
    if( a[i] == b[j] ) return lc[i][j] = 1 + lcs( i+1, j+1 );
    lc[i][j] = max( lcs( i+1, j ), lcs( i, j+1 ) );
    return lc[i][j];
}

ull rec( int i, int j, int l ) {
    if( i == a.size() and j == b.size() and !l ) return 1;
    if( i == a.size() and j == b.size() and l ) return 0;
    if( ~dp[i][j][l] ) return dp[i][j][l];
    if( i == a.size() and j != b.size() ) return dp[i][j][l] = rec( i, j+1, l-1 );
    if( i != a.size() and j == b.size() ) return dp[i][j][l] = rec( i+1, j, l-1 );
    if( a[i] == b[j] ) return dp[i][j][l] = rec( i+1, j+1, l-1 );
    dp[i][j][l] = rec( i+1, j, l-1 ) + rec( i, j+1, l-1 );
    return dp[i][j][l];
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, l;
    cin >> t;
    for( int cs=1; cs<=t; cs++ ) {
        cin >> a >> b;
        memset( lc, -1, sizeof lc );
        memset( dp, -1, sizeof dp );
        cout << "Case " << cs << ": " <<  ( l = a.size() + b.size() - lcs( 0, 0 ) ) << " ";
        cout << rec( 0, 0, l ) << "\n";
    }
    return 0;
}
