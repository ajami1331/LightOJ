#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > pii;
typedef pair < pii, int > piii;
const int mx = 1e5 + 1;
int BLOCK_SIZE;
int n, m, calc;
int cnt[mx];
int ar[mx];
int ans[mx];
piii query[mx];

bool cmp( const piii &a, const piii &b ) {
    int block_a = a.first.first / BLOCK_SIZE;
    int block_b = b.first.first / BLOCK_SIZE;
    if( block_a != block_b ) {
        return block_a < block_b;
    }
    return a.first.second < b.first.second;
}

void add( int x ) {
    if( !cnt[x] ) calc++;
    cnt[x]++;
}

void remove( int x ) {
    cnt[x]--;
    if( !cnt[x] ) calc--;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );

        BLOCK_SIZE = sqrt( n );
        memset( cnt, 0, sizeof cnt );
        calc = 0;

        for( int i=0; i<n; i++ ) scanf( "%d", ar+i );

        for( int i=0; i<m; i++ ) {
            scanf( "%d %d", &query[i].first.first, &query[i].first.second );
            query[i].second = i;
        }

        sort( query, query+m, cmp );

        int mo_l = 0, mo_r = -1;

        for( int i=0; i<m; i++ ) {
            int left = query[i].first.first - 1;
            int right = query[i].first.second - 1;

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

            ans[ query[i].second ] = calc;
        }

        printf( "Case %d:\n", cs );
        for( int i=0; i<m; i++ ) {
            printf( "%d\n", ans[i] );
        }
    }
    return 0;
}

