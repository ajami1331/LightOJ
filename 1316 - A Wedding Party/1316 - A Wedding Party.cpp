#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"
    
using ll = long long;
    
const int sz = 1e4 + 10;
const ll mod = 1e9 + 7;
int inf;
int t, cs;
int n, m, s, e;
int ar[505][505];
int shops[17];
int vis[17][1 << 17];
pair <int, int> dp[17][1 << 17];
vector <int> G[505];
int dist[505];
bool vi[505];

bool check(int mask, int bit) {
    return (mask >> bit) & 1;
}

int setBit(int mask, int bit) {
    return mask | (1 << bit);
}

int resetBit(int mask, int bit) {
    return mask & (~(1 << bit));
}

pair <int, int> rec(int u, int mask) {
    if (vis[u][mask] == cs) {
        return dp[u][mask]; 
    }
    vis[u][mask] = cs;
    pair <int, int> &ret = dp[u][mask];
    ret = make_pair(-inf, 0);
    if (ar[shops[u]][shops[s + 1]] < inf) {
        int m = __builtin_popcount(mask & (~((1 << 0) | (1 << (s + 1))))) + e;
        ret = make_pair(m, ar[shops[u]][shops[s + 1]]);
    }
    for (int i = 0; i <= s + 1; i++) {
        if (mask & (1 << i)) {
            continue;
        }
        if (ar[shops[u]][shops[i]] >= inf) {
            continue;
        }
        pair <int, int> tmp = rec(i, setBit(mask, i));
        tmp.second += ar[shops[u]][shops[i]];
        if ((tmp.first > ret.first) || (tmp.first == ret.first && tmp.second < ret.second)) {
            ret = tmp;
        }
    }
    return ret;
}

void dijk(int idx) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, shops[idx]));
    memset(dist, 31, sizeof dist);
    memset(vi, 0, sizeof vi);
    dist[shops[idx]] = 0;
    while (!pq.empty()) {
        pair <int, int> u = pq.top();
        pq.pop();
        for (int v: G[u.second]) {
            if (dist[v] > -u.first + ar[u.second][v]) {
                dist[v] = -u.first + ar[u.second][v];
                pq.push(make_pair(-dist[v], v));
            }
        }
    }
    for (int i = 0; i <= s + 1; i++) {
        ar[shops[idx]][shops[i]] = dist[shops[i]];
    }
}

int main() {
    
    scanf("%d", &t);
    
    for (cs = 1; cs <= t; cs++) {
        
        scanf("%d %d %d", &n, &m, &s);

        memset(ar, 31, sizeof ar);

        inf = ar[0][0];

        e = 0;

        for (int i = 0; i < n; i++) {
            G[i].clear();
        }

        for (int i = 1; i <= s; i++) {
            scanf("%d", &shops[i]);
            if (shops[i] == 0 || shops[i] == n - 1) {
                e++;
            }
        }

        shops[0] = 0;

        shops[s + 1] = n - 1;

        sort(shops, shops + s + 2);

        s = (unique(shops, shops + s + 2) - shops) - 2;
    
        for (int i = 0; i < m; i++) {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            G[x].push_back(y);
            ar[x][y] = min(ar[x][y], w);
        }

        for (int i = 0; i <= s; i++) {
            dijk(i);
        }

        pair <int, int> ans = rec(0, 1);

        printf("Case %d: ", cs);

        if (ans.first == -inf) {
            printf("Impossible\n");
        } else {
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    
    return 0;
}