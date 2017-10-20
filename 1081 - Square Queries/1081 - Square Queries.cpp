#include <bits/stdc++.h>
using namespace std;

const int sz = 505;

struct RMQ {
    int ar[sz];
    int tr[sz][9];
    int n;
    RMQ() {}
    void Read() {
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &ar[i] );
        }
    }
    void Build() {
        for( int i=0; i<n; i++ ) {
            tr[i][0] = ar[i];
        }
        for( int j=1; ( 1 << j ) <= n; j++ ) {
            for( int i=0; i + ( 1 << j ) - 1 < n; i++ ) {
                tr[i][j] = max( tr[i][j - 1], tr[ i + ( 1 << ( j - 1 ) ) ][j - 1] );
            }
        }        
    }
    int Query( int l, int r ) {
        int k = log2( r - l + 1 );
        return max( tr[l][k], tr[r - ( 1 << k ) + 1][k] );
    }

} rmq[sz];

int main() {
    int t, n, q, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &q );
        for( int i=0; i<n; i++ ) {
            rmq[i].n = n;
            rmq[i].Read();
            rmq[i].Build();
        }
        printf( "Case %d:\n", cs );
        for( int i=0,a,b,s; i<q; i++ ) {
            scanf( "%d %d %d", &a, &b, &s );
            --a, --b;
            ans = 0;
            for( int j=a; j<a+s; j++ ) {
                ans = max( ans, rmq[j].Query( b, b + s - 1 ) );
            }
            printf( "%d\n", ans );
        }
    }
    return 0;
}