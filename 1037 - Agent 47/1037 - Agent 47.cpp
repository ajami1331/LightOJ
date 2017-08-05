#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 28;
int he[15];
char dm[15][15];
int dmg[15][15];
int dp[(1<<15)+1];
int vs[(1<<15)+1];
int t, cs = 1, n;

int rec( int mask ) {
    if( mask == ( 1 << n ) - 1 ) return 0;
    if( vs[mask] == cs ) return dp[mask];

    int &ret = dp[mask];

    vs[mask] = cs;
    ret = inf ;

    for( int i=0; i<n; i++ ) {
        ret = min( ret, rec( mask | ( 1 << i ) ) + he[i] ) ;
    }

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<n; j++ ) {
            if( i == j ) continue;

            if( dmg[i][j] and ( mask & ( 1 << i ) ) and !( mask & ( 1 << j ) ) ) {

                    ret = min( ret, rec( mask | ( 1 << j ) ) + ( he[j] / dmg[i][j] ) + ( he[j] % dmg[i][j] ? 1 : 0 ) );
            }
        }
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    while( cs <= t ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) {
            scanf( "%d", he+i );
        }
        for( int i=0; i<n; i++ ) {
            scanf( "%s", dm[i] );
            for( int j=0; j<n; j++ ) {
                dmg[i][j] = dm[i][j] - '0';
            }
        }
        printf( "Case %d: %d\n", cs, rec( 0 ) );
        cs++;
    }
    return 0;
}
