#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int inf = 2e5 + 1;
bool vis[1001];
int dis[1001];
int s, d;
int pr[] = {
2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,
43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97, 101,
103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,
571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,
827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997  };

int bfs() {
    queue < int > q;
    memset( vis, 0, sizeof vis );
    memset( dis, -1, sizeof dis );
    vis[s] = 1;
    dis[s] = 0;
    q.push( s );
    int h;
    while( !q.empty() ) {
        h = q.front();
        q.pop();
        if( h == d ) return dis[h];
        for( int i=0, k = h; pr[i] <= h; i++ ) {
            if( h % pr[i] || k == pr[i] ) continue;
            while( h % pr[i] == 0 ) h /= pr[i];
            if( k + pr[i] <= d && !vis[ k + pr[i] ] ) {
                vis[ k + pr[i] ] = 1;
                dis[ k + pr[i] ] = dis[k] + 1;
                q.push( k + pr[i] );
            }
        }
    }
    return -1;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int t, h, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &s, &d );
        ans = bfs();
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
