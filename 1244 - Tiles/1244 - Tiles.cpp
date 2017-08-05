#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 10007;
const int mat_sz = 4;
struct Matrix {
    int a[mat_sz][mat_sz];
    void clear() {
        memset( a, 0, sizeof a );
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
        freopen("in.txt", "r", stdin);
    #endif // CLown1331
    rec.a[0][0] = 1;
    rec.a[0][1] = 1;
    rec.a[0][2] = 1;
    rec.a[0][3] = 1;

    rec.a[1][0] = 1;
    rec.a[1][1] = 0;
    rec.a[1][2] = 0;
    rec.a[1][3] = 0;

    rec.a[2][0] = 0;
    rec.a[2][1] = 1;
    rec.a[2][2] = 0;
    rec.a[2][3] = 1;

    rec.a[3][0] = 0;
    rec.a[3][1] = 1;
    rec.a[3][2] = 1;
    rec.a[3][3] = 0;

    int t, n;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        tmp = rec.pw( n );
        printf( "Case %d: %d\n", cs, tmp.a[0][0] );
    }
    return 0;
}
