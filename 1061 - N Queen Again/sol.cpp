#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 2e6 + 10;
const ll mod = 1000000007;

char s[8][8];

bool fl[8];
bool di[32];
int dp[8][1 << 8];

int ans;

vector < pair < int, int > > gen, vp;

int count( const pair < int, int >& a, const pair < int, int >& b ) {
        if( a.first == b.first && a.second == b.second ) return 0;
        if( a.first == b.first || a.second == b.second || ( abs( a.first - b.first ) == abs( a.second - b.second ) ) ) return 1;
        return 2;
}

int rec( int x, int mask ) {
        if( x == 8 ) return 0;
        int& ret = dp[x][mask];
        if( ~ret ) return ret;
        ret = 1 << 20;
        for( int i=0; i<8; i++ ) {
                if( ( mask & ( 1 << i ) ) == 0 ) {
                        ret = min( ret, rec( x + 1, mask | ( 1 << i ) ) + count( gen[i], vp[x] ) );
                }
        }
        return ret;
}

void solve( int x = 0 ) {
        if( x == 8 ) {
                memset( dp, -1, sizeof dp );
                ans = min( ans, rec( 0, 0 ) );
        }
        for( int y=0; y<8; y++ ) {
                int h = 0;
                for( int i=0; i<x; i++ ) {
                        if( ( abs( gen[i].first - x ) == abs( gen[i].second - y ) ) || ( gen[i].second == y ) ) {
                                h = 1;
                        }
                }
                if( h ) continue;
                gen.push_back( make_pair( x, y ) );
                solve( x + 1 );
                gen.pop_back();
        }
}

int main() {
#ifdef CLown1331
        freopen( "in.txt","r",stdin );
#endif /// CLown1331

        int t;

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                for( int i=0; i<8; i++ ) {
                        scanf( "%s", s[i] );
                }

                gen.clear();

                vp.clear();

                for( int i=0; i<8; i++ ) {
                        for( int j=0; j<8; j++ ) {
                                if( s[i][j] == 'q' ) {
                                        vp.push_back( make_pair( i, j ) );
                                }
                        }
                }

                ans = 1 << 20;

                solve();

                printf( "Case %d: %d\n", cs, ans );

        }

        return 0;
}