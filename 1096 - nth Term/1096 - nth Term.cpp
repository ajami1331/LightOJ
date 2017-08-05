#include <bits/stdc++.h>
using namespace std;

typedef vector < vector < int > >  matrix;
const int mod = 10007;

matrix multiply( const matrix &a, const matrix &b ) {
    matrix c = vector < vector < int > > ( 4, vector < int > ( 4, 0 ) );
    for( int k=0; k<4; k++ ) {
        for( int i=0; i<4; i++ ) {
            for( int j=0; j<4; j++ ) {
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
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, a, b, c, n;
    matrix mat = vector < vector < int > > ( 4, vector < int > ( 4, 0 ) );
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d %d", &n, &a, &b, &c );
        mat[0][0] = a % mod;
        mat[0][1] = 0;
        mat[0][2] = b % mod;
        mat[0][3] = 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
        mat[1][2] = 0;
        mat[1][3] = 0;
        mat[2][0] = 0;
        mat[2][1] = 1;
        mat[2][2] = 0;
        mat[2][3] = 0;
        mat[3][0] = 0;
        mat[3][1] = 0;
        mat[3][2] = 0;
        mat[3][3] = 1;
        printf( "Case %d: ", cs );
        if( n > 2 ) {
            mat = fast_expo( mat, n-2 );
            printf( "%d\n", ( mat[0][3] * c ) % mod );
        } else {
            printf( "0\n" );
        }
    }
    return 0;
}
