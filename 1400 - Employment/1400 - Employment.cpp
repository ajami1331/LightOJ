#include <bits/stdc++.h>
using namespace std;

int t, n;
int ar[201][101];
int partners[101];
int fl[101];

bool check( int w, int m, int m1 ) {
    for( int i=0; i<n; i++ ) {
        if( ar[w][i] == m1 ) return true;
        if( ar[w][i] == m ) return false;
    }
    return true;
}

void stable_match() {
    memset( partners, -1, sizeof partners );
    memset( fl, 0, sizeof fl );
    int cnt = n;
    int m, w, m1;
    while( cnt ) {
        for( m=0; m<n; m++ ) if( !fl[m] ) break;
        for( int i=0; i<n && !fl[m]; i++ ) {
            w = ar[m][i];
            if( partners[w-n] == - 1 ) {
                partners[w-n] = m;
                fl[m] = 1;
                cnt--;
            } else {
                m1 = partners[w-n];
                if( !check( w, m, m1 ) ) {
                    partners[w-n] = m;
                    fl[m] = 1;
                    fl[m1] = 0;
                }
            }
        }
    }
    for( int i=0; i<n; i++ ) {
        printf( " (%d %d)", partners[i]+1, i+n+1 );
    }
    printf( "\n" );
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<2*n; i++ ) {
            for( int j=0; j<n; j++ ) {
                scanf( "%d", &ar[i][j] );
                ar[i][j]--;
            }
        }
//        for( int i=0; i<2*n; i++ ) for( int j=0; j<n; j++ ) cerr << ar[i][j] << " \n"[ j == n-1 ];
        printf( "Case %d:", cs );
        stable_match();
    }
    return 0;
}
