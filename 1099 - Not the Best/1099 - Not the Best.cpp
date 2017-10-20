#include <stdio.h>
#include <vector>
#include <queue>
 
#define gc getchar_unlocked
 
using namespace std;
const int inf = 1 << 30;
struct nd {
    int y, w;
    bool operator < ( const nd &ot ) const {
        return w > ot.w;
    }
};
 
inline int RI() {
    int  ret = 0, flag = 1,ip = gc();
    for(; ip < 48 || ip > 57; ip = gc()) {
        if(ip == 45) {
            flag = -1;
            ip = gc();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = gc())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
 
 
int dis[5005];
int dis2[5005];
int par[5005];
int baje_x, baje_y, baje_w, dis1;
vector < nd > G[5005];
 
void dijk() {
    priority_queue < nd, vector < nd > > PQ;
    dis[1] = 0;
    PQ.push( { 1, 0 } );
    int x, y, w, ww, sz;
    while( !PQ.empty() ) {
        x = PQ.top().y;
        ww = PQ.top().w;
        PQ.pop();
        sz = G[x].size();
        for( int i=0; i<sz; i++ ) {
            y = G[x][i].y;
            w = G[x][i].w;
            if( dis[y] > ww + w ) {
                dis2[y] = dis[y];
                dis[y] = ww + w;
                par[y] = x;
                //baje_w = baje_w > w ? w : baje_w;
                PQ.push( { y, dis[y] } );
            }
            else if( dis2[y] > ww + w && dis[y] < ww + w ){
                dis2[y] = ww + w;
                PQ.push( { y, dis2[y] } );
            }
        }
    }
}
 
int main() {
    int t, n, r;
    t = RI();
    for( int cs=1; cs<=t; cs++ ) {
        n = RI(); r = RI();
        for( int i=0; i<=n; i++ ) {
            G[i].clear();
            dis[i] = inf;
            dis2[i] = inf;
        }
        for( int i=0,x,y,w; i<r; i++ ) {
            x = RI(); y = RI(); w = RI();
            G[ x ].push_back( { y, w } );
            G[ y ].push_back( { x, w } );
        }
        baje_w = inf;
        dijk();
        //dis1 = dis[n] + baje_w + baje_w;
        printf( "Case %d: %d\n", cs, dis2[n] );
    }
    return 0;
}
