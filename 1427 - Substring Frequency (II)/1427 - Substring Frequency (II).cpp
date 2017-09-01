#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int sz = 1e6 + 10;
const int MAX = 505 * 505 + 100;
char inp[sz], s[505][505];
int cnt[505];

struct AhoCorasick {
    vector < int > mark[MAX + 7];
    int state, failure[MAX + 7];
    int trie[MAX + 7][ 26 ];

    AhoCorasick() {
        init();
    }

    void init() {
        mark[0].clear();
        fill( trie[0], trie[0] + 26, -1 );
        state = 0;
    }

    int value( char c ) {
        return c - 'a';
    }

    void add( char *s, int t ) {
        int root = 0, id;
        for( int i=0; s[i]; i++ ) {
            id = value( s[i] );
            if( trie[ root ][ id ] == -1 ) {
                trie[ root ][ id ] = ++state;
                mark[state].clear();
                fill( trie[state], trie[state + 1] + 26, - 1 );
            }
            root = trie[ root ][ id ];
        }
        mark[ root ].push_back( t );
    }

    void computeFailure() {
        queue < int > Q;
        failure[0] = 0;
        for( int i=0; i<26; i++ ) {
            if( trie[ 0 ][ i ] != -1 ) {
                failure[ trie[ 0 ][ i ] ] = 0;
                Q.push( trie[ 0 ][ i ] );
            }
            else trie[ 0 ][ i ] = 0;
        }
        while( !Q.empty() ) {
            int u = Q.front();
            Q.pop();
            for( int i=0; i<mark[ failure[ u ] ].size(); i++ ) mark[ u ].push_back( mark[ failure[ u ] ][ i ] );
            for( int i=0; i<26; i++ ) {
                if( trie[ u ][ i ] != -1 ) {
                    failure[ trie[ u ][ i ] ] = trie[ failure[ u ] ][ i ];
                    Q.push( trie[ u ][ i ] );
                }
                else trie[ u ][ i ] = trie[ failure[ u ] ][ i ];
            }
        }
    }
} automata;

void countFreq() {
    for( int i=0,root=0,id; inp[i]; i++ ) {
        id = automata.value( inp[i] );
        root = automata.trie[ root ][ id ];
        if( root == 0 ) continue;
        for( int i=0; i<automata.mark[ root ].size(); i++ ) cnt[ automata.mark[ root ][ i ] ]++;
    }
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt","r",stdin );
    #endif /// CLown1331
    int t, n, cs;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        scanf( "%s", inp );
        automata.init();
        for( int i=0; i<n; i++ ) {
            scanf( "%s", s[i] );
            automata.add( s[i], i );
        }
        automata.computeFailure();
        memset( cnt, 0, sizeof cnt );
        countFreq();
        printf( "Case %d:\n", cs );
        for( int i=0; i<n; i++ ) {
            printf( "%d\n", cnt[i] );
        }
    }
    return 0;
}
