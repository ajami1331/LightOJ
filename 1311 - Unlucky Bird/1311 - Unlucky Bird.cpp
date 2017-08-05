#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    int t, cs;
    double v1, v2, v3, a1, a2, ans, time1, time2, time3, dist;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2 );
        time1 = v1 / a1;
        time2 = v2 / a2;
        time3 = max( time1, time2 );
        ans = time3 * v3;
        dist = v1 * time1 - 0.5 * a1 * time1 * time1;
        dist += v2 * time2 - 0.5 * a2 * time2 * time2;
        printf( "Case %d: %f %f\n", cs, dist, ans );
    }
    return 0;
}
