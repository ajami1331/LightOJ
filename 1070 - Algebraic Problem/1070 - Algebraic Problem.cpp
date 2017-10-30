#include <stdio.h>
#include <string.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int mat_sz = 2;
struct Matrix {
    ull a[mat_sz][mat_sz];
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
                    tmp.a[i][k] += a[i][j] * b.a[j][k];
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
} base;

int main() {
    int t, p, q, n;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d %d", &p, &q, &n );
        base.a[0][0] = p;
        base.a[0][1] = -q;
        base.a[1][0] = 1;
        base.a[1][1] = 0;
        printf( "Case %d: ", cs );
        if( n == 0 ) {
            printf( "2\n" );
        }
        else {
            base = base.pw( n - 1 );
            printf( "%llu\n", base.a[0][0] * p + base.a[0][1] * 2 );
        }
    }
    return 0;
}