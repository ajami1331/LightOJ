#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
 
using ll = long long;
 
const int sz = 3e4 + 10;
 
#define sqr( a ) ( ( a ) * ( a ) )

int t, cs, n, k, m;
double p;

double dp[105][105];
int vp[105][105];

double rec(int x, int y) {
        if (x == k) return y * n;
        if (vp[x][y] == cs) return dp[x][y];
        vp[x][y] = cs;
        dp[x][y] = (rec(x + 1, y) * (1.0 - p)) + (rec(x + 1, y + 1) * p);
        return dp[x][y];
}

int main() {

        scanf("%d", &t);

        for (cs = 1; cs <= t; cs++) {

                scanf("%d %d %d %lf", &n, &m, &k, &p);

                printf("Case %d: %.12f\n", cs, rec(0, 0));
        }

        return 0;
}