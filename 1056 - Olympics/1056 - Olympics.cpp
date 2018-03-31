#include <bits/stdc++.h>
using namespace std;

const double PI = acos( -1 );
const double eps = 1e-6;
const double pera_ = 400.0;

double ansL, ansW;
int a, b;

void solve() {
        double lo = 0.0;
        double hi = 800.0;
        double length, width, mid, diag, angle;
        double para;
        for( int i=0; i<64; i++ ) {
                mid = ( hi + lo ) / 2.0;
                length = mid;
                width = ( length / a ) * b;
                diag = sqrt( width * width + length * length );
                angle = acos( length / diag );
                para = length * 2.0;
                para += 2.0 * angle * diag;
                if( para > pera_ )
                        hi = mid;
                else
                        lo = mid;
        }
        ansL = length;
        ansW = width;
}

int main() {
#ifdef CLown1331
        freopen( "in.txt", "r", stdin );
#endif /// CLown1331
        int t, n, ans, q;
        scanf( "%d", &t );
        for( int cs=1; cs<=t; cs++ ) {
                scanf( "%d : %d", &a, &b );
                solve();
                printf( "Case %d: %.6f %.6f\n", cs, ansL, ansW );
        }
        return 0;
}

