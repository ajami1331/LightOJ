#include <bits/stdc++.h>
using namespace std;

const int sz = 1005;
const int lim = 1e9 + 1;

int t, n, cs;
int plx[4], ply[4], k;
char s[12][12];
int v1[12][12];
int v2[12][12];
int v3[12][12];
int v[12][12][12][12][12][12];

int dx[] = { +1, +0, -1, -0 };
int dy[] = { +0, +1, -0, -1 };

int valid( int x, int y ) {
        if( x < 0 || y < 0 || x >= n || y >= n || s[x][y] == '#' ) return 0;
        return 1;
}

int solve() {

        memset( v, 0, sizeof v );

        memset( v1, 0, sizeof v1 );

        memset( v2, 0, sizeof v2 );

        memset( v3, 0, sizeof v3 );

        queue < int > Q;

        v1[ plx[0] ][ ply[0] ] = 1;
        v2[ plx[1] ][ ply[1] ] = 1;
        v3[ plx[2] ][ ply[2] ] = 1;

        Q.push( plx[0] );
        Q.push( ply[0] );
        Q.push( plx[1] );
        Q.push( ply[1] );
        Q.push( plx[2] );
        Q.push( ply[2] );

        int ulx[4], uly[4];
        int vlx[4], vly[4];

        v[ plx[0] ][ ply[0] ][ plx[1] ][ ply[1] ][ plx[2] ][ ply[2] ] = 1;

        while( !Q.empty() ) {
                ulx[0] = Q.front(); Q.pop();
                uly[0] = Q.front(); Q.pop();

                ulx[1] = Q.front(); Q.pop();
                uly[1] = Q.front(); Q.pop();

                ulx[2] = Q.front(); Q.pop();
                uly[2] = Q.front(); Q.pop();

//                cerr << "\n";
//                cerr << ulx[0] << " " << uly[0] << " | ";
//                cerr << ulx[1] << " " << uly[1] << " | ";
//                cerr << ulx[2] << " " << uly[2] << "\n";

                for( int i=0; i<4; i++ ) {
                        vlx[0] = ulx[0] + dx[i];
                        vly[0] = uly[0] + dy[i];

                        vlx[1] = ulx[1] + dx[i];
                        vly[1] = uly[1] + dy[i];

                        vlx[2] = ulx[2] + dx[i];
                        vly[2] = uly[2] + dy[i];

                        if( !valid( vlx[0], vly[0] ) ) vlx[0] = ulx[0], vly[0] = uly[0];

                        if( !valid( vlx[1], vly[1] ) ) vlx[1] = ulx[1], vly[1] = uly[1];

                        if( !valid( vlx[2], vly[2] ) ) vlx[2] = ulx[2], vly[2] = uly[2];

                        if( vlx[0] == vlx[1] && vly[0] == vly[1] ) {
                                if( ulx[0] + dx[i] == vlx[1] && uly[0] + dy[i] == vly[1] ) {
                                        vlx[0] = ulx[0];
                                        vly[0] = uly[0];
                                }
                                else {
                                        vlx[1] = ulx[1];
                                        vly[1] = uly[1];
                                }
                        }

                        if( vlx[1] == vlx[2] && vly[1] == vly[2] ) {
                                if( ulx[2] + dx[i] == vlx[1] && uly[2] + dy[i] == vly[1] ) {
                                        vlx[2] = ulx[2];
                                        vly[2] = uly[2];
                                }
                                else {
                                        vlx[1] = ulx[1];
                                        vly[1] = uly[1];
                                }
                        }

                        if( vlx[2] == vlx[0] && vly[2] == vly[0] ) {
                                if( ulx[2] + dx[i] == vlx[0] && uly[2] + dy[i] == vly[0] ) {
                                        vlx[2] = ulx[2];
                                        vly[2] = uly[2];
                                }
                                else {
                                        vlx[0] = ulx[0];
                                        vly[0] = uly[0];
                                }
                        }

                        if( vlx[0] == vlx[1] && vly[0] == vly[1] ) continue;

                        if( vlx[1] == vlx[2] && vly[1] == vly[2] ) continue;

                        if( vlx[2] == vlx[0] && vly[2] == vly[0] ) continue;

                        if( v[ vlx[0] ][ vly[0] ][ vlx[1] ][ vly[1] ][ vlx[2] ][ vly[2] ] == 0 ) {
                                Q.push( vlx[0] );
                                Q.push( vly[0] );

                                Q.push( vlx[1] );
                                Q.push( vly[1] );

                                Q.push( vlx[2] );
                                Q.push( vly[2] );

                                v[ vlx[0] ][ vly[0] ][ vlx[1] ][ vly[1] ][ vlx[2] ][ vly[2] ] =
                                                1 + v[ ulx[0] ][ uly[0] ][ ulx[1] ][ uly[1] ][ ulx[2] ][ uly[2] ];

                                if(
                                        s[ vlx[0] ][ vly[0] ] == s[ vlx[1] ][ vly[1] ]
                                                &&
                                        s[ vlx[1] ][ vly[1] ] == s[ vlx[2] ][ vly[2] ]
                                                        &&
                                        s[ vlx[2] ][ vly[2] ] == 'X'
                                ) {

//                                        cerr << "\n";
//                                        cerr << vlx[0] << " " << vly[0] << " | ";
//                                        cerr << vlx[1] << " " << vly[1] << " | ";
//                                        cerr << vlx[2] << " " << vly[2] << "\n";
//
//                                        cerr << "\n";
//                                        cerr << s[ vlx[0] ][ vly[0] ] << " | ";
//                                        cerr << s[ vlx[1] ][ vly[1] ] << " | ";
//                                        cerr << s[ vlx[2] ][ vly[2] ] << "\n";

                                        return v[ ulx[0] ][ uly[0] ][ ulx[1] ][ uly[1] ][ ulx[2] ][ uly[2] ];
                                }
                        }
                }
        }

        return -1;
}

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( cs=1; cs<=t; cs++ ) {

                scanf( "%d", &n );

                for( int i=0; i<n; i++ ) {
                        scanf( "%s", s[i] );
                        for( int j=0; j<n; j++ ) {
                                if( s[i][j] == 'A' ) plx[0] = i, ply[0] = j;
                                if( s[i][j] == 'B' ) plx[1] = i, ply[1] = j;
                                if( s[i][j] == 'C' ) plx[2] = i, ply[2] = j;
                        }
                }

                printf( "Case %d: ", cs );

                int ans = solve();

                if( ans == -1 ) printf( "trapped\n" );
                else printf( "%d\n", ans );

//                cerr << "----\n";

        }

        return 0;
}
