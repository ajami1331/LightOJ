#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;

#define sqr( a ) ( ( a ) * ( a ) )

int t, cs, a, b, n, m;
int mod, ans;

const int sz = 1e6 + 10;

template <int mat_sz> struct Matrix {
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
};


Matrix <2> tmp, fn;

int main() {

        scanf("%d", &t);

        fn.a[0][0] = 1;
        fn.a[0][1] = 1;
        fn.a[1][0] = 1;
        fn.a[1][1] = 0;

        for (int cs = 1; cs <= t; cs++) {

            scanf("%d %d %d %d", &a, &b, &n, &m);

            switch (m)
            {
            case 1:
                mod = 10;
                break;
            case 2:
                mod = 100;
                break;
            case 3:
                mod = 1000;
                break;
            case 4:
                mod = 10000;
                break;
            default:
                break;
            }

            switch (n)
            {
            case 0:
                ans = a % mod;
                break;
            case 1:
                ans = b % mod;
                break;
            default:
                tmp = fn.pw(n - 1);
                ans = ((tmp.a[0][0] * b) + (tmp.a[0][1] * a)) % mod;
                break;
            }

            printf( "Case %d: %d\n", cs, ans);
        }

        return 0;
}
