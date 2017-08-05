#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mx = 2e5 + 1;
const double pi = acos( -1.0 );

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t;
    double r, n, ans, alpha, ratio;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%lf %lf", &r, &n );
        alpha = ( ( 2.0 * pi ) / n ) / 2.0;
        ratio = sin( alpha );
        ans = ( ratio * r ) / ( ratio + 1 );
        printf( "Case %d: %.8lf\n", cs, ans );
    }
    return 0;
}
