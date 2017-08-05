#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;
int BLOCK_SIZE;
int n, m;
int ar[mx];
int ans[mx];
int cnt[1001];

struct qq{
    int x, y, blk, id;
    bool operator <( const qq &ot ) const{
        if( blk != ot.blk ) {
            return blk < ot.blk;
        }
        return y < ot.y;
    }
} query[mx];

struct {
    bool operator()( const qq &a, const qq &b ) {
        if( a.blk != b.blk ) {
            return a.blk < b.blk;
        }
        return a.y < b.y;
    }
} cmp;

void add( int x ) {
    cnt[x]++;
}

void remove( int x ) {
    cnt[x]--;
}

int calc() {
    int pre = -1, ans = 2e4;
    for( int i=1; i<1001; i++ ) {
        if( cnt[i] ) {
            if( cnt[i] >= 2 ) return 0;
            if( pre != -1 ) {
                ans = min( ans, i - pre );
            }
            pre = i;
        }
    }
    return ans;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int n, m, t, cs = 0;
    scanf( "%d", &t );
    while( t-- && ~scanf( "%d %d", &n, &m ) ) {

        BLOCK_SIZE = sqrt( n );
        memset( cnt, 0, sizeof cnt );
        for( int i=0; i<n; i++ ) scanf( "%d", ar+i );

        for( int i=0; i<m; i++ ) {
            scanf( "%d %d", &query[i].x, &query[i].y );
            query[i].id = i;
            query[i].blk = query[i].x / BLOCK_SIZE;
        }


        sort( query, query+m );

        int mo_l = 0, mo_r = -1;

        for( int i=0; i<m; i++ ) {
            int left = query[i].x;
            int right = query[i].y;

            while( mo_r < right ) {
                mo_r++;
                add( ar[mo_r] );
            }

            while( mo_r > right ) {
                remove( ar[mo_r] );
                mo_r--;
            }

            while( mo_l < left ) {
                remove( ar[mo_l] );
                mo_l++;
            }

            while( mo_l > left ) {
                mo_l--;
                add( ar[mo_l] );
            }

            ans[ query[i].id ] = calc();
        }
        printf( "Case %d:\n", ++cs );
        for( int i=0; i<m; i++ ) {
            printf( "%d\n", ans[i] );
        }
    }
    return 0;
}
