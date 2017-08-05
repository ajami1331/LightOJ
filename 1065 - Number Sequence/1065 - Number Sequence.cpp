#include <bits/stdc++.h>
using namespace std;

typedef vector < vector < int > >  matrix;
int mod = 1e9 + 7;

matrix multiply( const matrix &a, const matrix &b ) {
    matrix c = vector < vector < int > > ( 2, vector < int > ( 2, 0 ) );
    for( int k=0; k<2; k++ ) {
        for( int i=0; i<2; i++ ) {
            for( int j=0; j<2; j++ ) {
                c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % mod;
            }
        }
    }
    return c;
}

matrix fast_expo( const matrix &m, int n ) {
    if( n == 1 ) {
        return m;
    }
    if( n & 1 ) {
        return multiply( m, fast_expo( m, n-1 ) );
    }
    matrix a = fast_expo( m, n >> 1 );
    return multiply( a, a );
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, a, b, n, m;
    matrix mat = vector < vector < int > > ( 2, vector < int > ( 2, 0 ) );
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d %d", &a, &b, &n, &m );
        if( m == 1 ) mod = 10;
        else if( m == 2 ) mod = 100;
        else if( m == 3 ) mod = 1000;
        else if( m == 4 ) mod = 10000;
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
        printf( "Case %d: ", cs );
        if( n > 1 ) {
            mat = fast_expo( mat, n-1 );
            printf( "%d\n", ( ( mat[0][0] * b ) + ( mat[0][1] * a ) ) % mod );
        } else {
            if( n == 0 ) printf( "%d\n", a % mod );
            else printf( "%d\n", b % mod );
        }
    }
    return 0;
}
