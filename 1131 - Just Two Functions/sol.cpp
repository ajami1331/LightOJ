#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

const int sz = 1005;

#define sqr( a ) ( ( a ) * ( a ) )

int t, q, n, a, b, mod, c[6];
int coef[2][3], fn[2][3];

const int mat_sz = 6;
struct Matrix {
    int a[mat_sz][mat_sz];
    void clear() {
        memset(a, 0, sizeof(a));
    }
    void one() {
        for( int i=0; i<mat_sz; i++ ) {
            for( int j=0; j<mat_sz; j++ ) {
                a[i][j] = i == j;
            }
        }
    }
    Matrix operator + (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i <  mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                tmp.a[i][j] = a[i][j] + b.a[i][j];
                if (tmp.a[i][j] >= mod) {
                    tmp.a[i][j] -= mod;
                }
            }
        }
        return tmp;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i < mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                for (int k = 0; k < mat_sz; k++) {
                    tmp.a[i][k] += (long long)a[i][j] * b.a[j][k] % mod;
                    if (tmp.a[i][k] >= mod) {
                        tmp.a[i][k] -= mod;
                    }
                }
            }
        }
        return tmp;
    }
    Matrix pw(int x) {
        Matrix ans, num = *this;
        ans.one();
        while (x > 0) {
            if (x & 1) {
                ans = ans * num;
            }
            num = num * num;
            x >>= 1;
        }
        return ans;
    }
} rec, tmp;

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        scanf( "%d", &t );
 
        for( int cs=1; cs<=t; cs++ ) {

                for( int i=0; i<2; i++ ) {
                        for( int j=0; j<3; j++ ) {
                                scanf( "%d", &coef[i][j] );
                        }
                }

                for( int i=0; i<2; i++ ) {
                        for( int j=0; j<3; j++ ) {
                                scanf( "%d", &fn[i][j] );
                        }
                }

                scanf( "%d", &mod );

                rec.clear();

                rec.a[0][0] = coef[0][0] % mod;
                rec.a[0][1] = coef[0][1] % mod;
                rec.a[0][5] = coef[0][2] % mod;

                rec.a[1][0] = 1;

                rec.a[2][1] = 1;

                rec.a[3][2] = coef[1][2] % mod;
                rec.a[3][3] = coef[1][0] % mod;
                rec.a[3][4] = coef[1][1] % mod;

                rec.a[4][3] = 1;

                rec.a[5][4] = 1;                

                c[0] = fn[0][2] % mod;
                c[1] = fn[0][1] % mod;
                c[2] = fn[0][0] % mod;
                c[3] = fn[1][2] % mod;
                c[4] = fn[1][1] % mod;
                c[5] = fn[1][0] % mod;

                scanf( "%d" , &q );

                printf( "Case %d:\n", cs );

                while( q--  ){
                        scanf( "%d", &n );
                        if( n > 2 ) {
                                tmp = rec.pw( n - 2 );
                                a = 0;
                                b = 0;
                                for( int i=0; i<6; i++ ) {
                                        a = ( a + ( ( tmp.a[0][i] * c[i] ) % mod ) ) % mod;
                                        b = ( b + ( ( tmp.a[3][i] * c[i] ) % mod ) ) % mod;
                                }
                        }
                        else {
                                a = fn[0][n] % mod;
                                b = fn[1][n] % mod;
                        }
                        printf( "%d %d\n", a, b );
                }
 
        }
 
        return 0;
}
