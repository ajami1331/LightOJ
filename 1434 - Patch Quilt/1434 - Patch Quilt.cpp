#include <bits/stdc++.h>
using namespace std;
int t;
char mp[40][40];
char s[25];
int n, len, r, c;
int dp[40][40][20];

int rec( int x, int y, int k ) {
    if( x >= r || y >= c || x < 0 || y < 0 ) return 0;
    if( mp[x][y] != s[k] ) return dp[x][y][k] = 0;
    if( k == len - 1 ) {
        if( mp[x][y] == s[k] ) {
            return dp[x][y][k] = 1;
        }
        else {
            return dp[x][y][k] = 0;
        }
    }
    int &ret = dp[x][y][k];
    if( ~ret ) return ret;
    ret = 0;

    ret |= rec( x, y, k+1 );

    ret |= rec( x+1, y, k+1 );
    ret |= rec( x, y+1, k+1 );
    ret |= rec( x, y-1, k+1 );
    ret |= rec( x-1, y, k+1 );

    ret |= rec( x+1, y+1, k+1 );
    ret |= rec( x+1, y-1, k+1 );
    ret |= rec( x-1, y+1, k+1 );
    ret |= rec( x-1, y-1, k+1 );

    return ret;
}

vector < string > ans;

void print( int x, int y, int k ) {
    if( k == len - 1 ) {
        return;
    }
    int ret = 0;

    ret |= rec( x, y, k+1 );
    if( ret ) {
        ans.push_back( "*" );
        print( x, y, k+1 );
        return;
    }

    ret |= rec( x+1, y, k+1 );
    if( ret ) {
        ans.push_back( "D" );
        print( x+1, y, k+1 );
        return;
    }

    ret |= rec( x, y+1, k+1 );
    if( ret ) {
        ans.push_back( "R" );
        print( x, y+1, k+1 );
        return;
    }

    ret |= rec( x, y-1, k+1 );
    if( ret ) {
        ans.push_back( "L" );
        print( x, y-1, k+1 );
        return;
    }

    ret |= rec( x-1, y, k+1 );
    if( ret ) {
        ans.push_back( "U" );
        print( x-1, y, k+1 );
        return;
    }

    ret |= rec( x+1, y+1, k+1 );
    if( ret ) {
        ans.push_back( "DR" );
        print( x+1, y+1, k+1 );
        return;
    }

    ret |= rec( x+1, y-1, k+1 );
    if( ret ) {
        ans.push_back( "DL" );
        print( x+1, y-1, k+1 );
        return;
    }

    ret |= rec( x-1, y+1, k+1 );
    if( ret ) {
        ans.push_back( "UR" );
        print( x-1, y+1, k+1 );
        return;
    }

    ret |= rec( x-1, y-1, k+1 );
    if( ret ) {
        ans.push_back( "UL" );
        print( x-1, y-1, k+1 );
        return;
    }

    return;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif /// CLown1331
    scanf( "%d", &t );
    int sx, sy, fl;
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &r, &c ) ;
        for( int i=0; i<r; i++ ) scanf( "%s", mp[i] );
        scanf( "%d", &n );
        printf( "Case %d:\n", cs );
        while( n-- ) {
            scanf( "%s", s );
            len = strlen( s );
            memset( dp, -1, sizeof dp );
            fl = 0;
            for( int i=0; i<r && !fl; i++ ) {
                for( int j=0; j<c; j++ ) {
                    if( rec( i, j, 0 ) ) {
                        fl = 1;
                        sx = i;
                        sy = j;
                        break;
                    }
                }
            }
            if( !fl ) {
                printf( "%s not found\n", s );
            }
            else {
                ans.clear();
                printf( "%s found: ", s );
                print( sx, sy, 0 );
                printf( "(%d,%d)", sx+1, sy+1 );
                for( int i=0; i<ans.size(); i++ ) {
                    printf( ", %s", ans[i].c_str() );
                }
                printf( "\n" );
            }
        }
    }
    return 0;
}
