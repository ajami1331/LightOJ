#include <bits/stdc++.h>
using namespace std;

char mp[26][26];
int ghost[26][26];
int human[26][26];
int cost[666][666];
int h, g;
int dx[] = { +1, -1, +0, +0 };
int dy[] = { +0, +0, -1, +1 };

struct nd {
    int x, y, z;
};

int fl[666];
int vis[26][26];
int match[666];
int cap;

bool bpm( int u ) {
    for( int v=0; v<h; v++ ) {
        if( cost[u][v] && cost[u][v] <= cap && !fl[v] ) {
            fl[v] = true;
            if( match[v] == -1 || bpm( match[v] ) ) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int max_match( int n, int mid ) {
    cap = mid;
    memset( match, -1, sizeof match );
    int ret = 0;
    for( int i=0; i<n; i++ ) {
        memset( fl, 0, sizeof fl );
        if( bpm( i ) ) {
            ret++;
        }
    }
    return ret;
}


int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    int t, n, lo, hi, mid;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) {
            scanf( "%s", mp[i] );
//            cerr << mp[i] << "\n";
        }
        h = 0;
        g = 0;
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                if( mp[i][j] == 'G' ) ghost[i][j] = g++;
                if( mp[i][j] == 'H' ) human[i][j] = h++;
            }
        }


      lo = 0;
      hi = 0;

      memset( cost, 0, sizeof cost ) ;

      for( int i=0; i<n; i++ ) {
          for( int j=0; j<n; j++ ) {
              if( mp[i][j] == 'G' ) {
                  queue < nd > Q;
                  Q.push( { i, j, 0 } );
                  memset( vis, 0, sizeof vis );
                  int x, y, z;
                  int nx, ny, nz;
                  vis[i][j] = 1;
                  while( !Q.empty() ) {
                      x = Q.front().x;
                      y = Q.front().y;
                      z = Q.front().z;
                      Q.pop();
                      for( int k=0; k<4; k++ ) {
                          nx = dx[k] + x;
                          ny = dy[k] + y;
                          nz = z + 1;
                          if( nx < 0 || nx >= n || ny < 0 || ny >=n || mp[nx][ny] == '#' || vis[nx][ny] ) continue;
                          vis[nx][ny] = 1;
                          if( mp[nx][ny] == 'H' ) {
//                              printf( "(%d,%d) - > (%d,%d) : %d\n", i, j, nx, ny, nz * 2 + 2 );
                              cost[ ghost[i][j] ][ human[nx][ny] ] = nz * 2 + 2;
                              hi = max( hi, nz * 2 + 2 );
                          }
                          Q.push( { nx, ny, nz } );
                      }
                    }
                }
            }
        }


//        cerr << "done\n";
//
//        cerr << g << "\n";
//
//        for( int i=0; i<g; i++ ) {
//            for( int j=0; j<g; j++ ) {
//                cerr << cost[i][j] << " ";
//            }
//            cerr << "\n";
//        }

        printf( "Case %d: ", cs );

        mid = hi;

        if( max_match( g, mid ) != h ) {
            printf( "Vuter Dol Kupokat\n" );
        } else {
            while( hi - lo > 4 ) {
                mid = ( hi + lo ) >> 1;
//                cerr << lo << " " << mid << " " << hi << "\n";
                if( max_match( g, mid ) != h ) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            int ck = 0;
//            cerr << lo << " " << hi << "\n";
            while( lo <= hi ) {
                if( max_match( g, lo ) == h ) {
                    ck = 1;
                    break;
                }
                lo++;
            }
            if( ck ) {
                printf( "%d\n", lo );
            } else {
                printf( "Vuter Dol Kupokat\n" );
            }
        }
    }
    return 0;
}
