#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
double p[101], dp[101][10001], x;
int n, mil[101];

double rec( int i, int j ) {
    if( j <= 0 ) return 0;
    if( i < 0 ) return 1;
    if( dp[i][j] > -1 ) return dp[i][j];
    double &ret = dp[i][j];
    ret = rec( i-1, j );
    ret = min( ret, p[i] + ( 1.0 - p[i] ) * rec( i-1, j-mil[i] ) );
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, hi, lo, mid;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%lf %d", &x, &n );
        hi = 0; lo = 0;
        for( int i=0; i<n; i++ ) {
            scanf( "%d %lf", &mil[i], &p[i] );
            hi += mil[i];
        }
        memset( dp, -1, sizeof dp );
        while( hi - lo >= 4 ) {
            mid = ( hi + lo ) / 2;
            if( rec( n-1, mid ) < x ) lo = mid;
            else hi = mid - 1;
        }
        while( hi >= lo ) {
            if( rec( n-1, hi ) < x ) break;
            hi--;
        }
        printf( "Case %d: %d\n", cs, hi );
    }
    return 0;
}
