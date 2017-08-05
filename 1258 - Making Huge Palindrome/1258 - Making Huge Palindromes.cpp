#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 1;
char a[mx], b[mx];
int table[mx], lenA, lenB;

void hash_table( char *s ) {
    table[ 0 ] = 0;
    int i = 1, j = 0;
    while( i < lenB ) {
        if( s[i] == s[j] ) {
            j++;
            table[ i ] = j;
            i++;
        } else {
            if( j ) {
                j = table[ j - 1 ];
            } else {
                table[ i ] = 0;
                i++;
            }
        }
    }
}

int kmp( char *s, char *m ) {
    hash_table( m );
    int i = 0, j = 0;
    int ans = 0;
    while( i < lenA ) {
        while( i < lenA && j < lenB && s[i] == m[j] ) {
            i++;
            j++;
            ans++;
        }
        if( j == lenB ) {
            j = table[ j - 1 ];
        } else if( i < lenA && s[i] != m[j] ) {
            ans = 0;
            if( j ) {
                ans += table[ j - 1 ];
                j = table[ j - 1 ];
            } else {
                i++;
            }
        }
    }
    return ans;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%s", a );
        lenA = strlen( a );
        lenB = lenA;
        for( int i=0; i<lenA; i++ ) b[i] = a[lenA-i-1];
        ans = lenA + ( lenA - kmp( a, b ) );
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
