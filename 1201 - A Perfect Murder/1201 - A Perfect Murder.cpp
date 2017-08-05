#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int inf = 1e9;
int clr[1001];
VVI g;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w ) {
    VI mr = VI(w.size(), -1);
    VI mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, x, y, n, m, h;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        g = VVI( n, VI( n, 0 ) );
        while( m-- ) {
            scanf( "%d %d", &x, &y );
            --x, --y;
            g[x][y] = 1;
            g[y][x] = 1;
        }
        h = BipartiteMatching( g );
//        cerr << h << " " << h / 2 << " ";
        h = n - h / 2;
        printf( "Case %d: %d\n", cs, h );
    }
    return 0;
}
