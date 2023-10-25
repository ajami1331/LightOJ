#ifndef solution_h
#define solution_h 1
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
namespace solution
{
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int sz = 1e4 + 105;
vector<int> G[sz];
int t, tim, root, n, m, a, b;
int ap[sz], vis[sz], low[sz], d[sz], par[sz];
map<int, map<int, bool>> mp;
pair<int, int> ed[sz * 3];
set<int> st;
void ap_dfs(int u)
{
    tim++;
    int cnt = 0;
    low[u] = tim;
    d[u] = tim;
    vis[u] = 1;
    int v;
    for (int i = 0; i < G[u].size(); i++)
    {
        v = G[u][i];
        if (v == par[u])
            continue;
        if (!vis[v])
        {
            par[v] = u;
            ap_dfs(v);
            low[u] = min(low[u], low[v]);
            if (d[u] < low[v])
            {
                ap[u] = 1;
                mp[u][v] = 1;
                mp[v][u] = 1;
            }
            cnt++;
        }
        else
        {
            low[u] = min(low[u], d[v]);
        }
    }
}
int find_rep(int x)
{
    return par[x] == x ? x : par[x] = find_rep(par[x]);
}
void Solve()
{
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        scanf("%d %d", &n, &m);
        mp.clear();
        for (int i = 0; i <= n; i++)
        {
            G[i].clear();
            ap[i] = 0;
            vis[i] = 0;
            low[i] = 0;
            d[i] = 0;
            par[i] = -1;
        }
        for (int i = 0, x, y; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
            ed[i].first = x;
            ed[i].second = y;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i])
            {
                continue;
            }
            ap_dfs(i);
        }
        for (int i = 0; i <= n; i++)
            par[i] = i;
        for (int i = 0, x, y; i < m; i++)
        {
            x = ed[i].first;
            y = ed[i].second;
            if (mp[x][y])
            {
                continue;
            }
            x = find_rep(x);
            y = find_rep(y);
            if (par[x] != par[y])
            {
                par[x] = par[y];
            }
        }
        map <int, int> deg;
        for (int i = 0, x, y; i < m; i++)
        {
            x = ed[i].first;
            y = ed[i].second;
            x = find_rep(x);
            y = find_rep(y);
            if (par[x] != par[y])
            {
                deg[par[x]]++;
                deg[par[y]]++;
            }
        }
        int leaf = 0;
        for (auto it : deg)
        {
            if (it.second == 1)
            {
                leaf++;
            }
        }
        printf("Case %d: %d\n", cs, (leaf + 1) / 2);
    }
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
