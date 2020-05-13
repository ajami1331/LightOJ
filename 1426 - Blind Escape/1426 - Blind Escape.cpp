#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-std=c++11"

using ll = long long;

const int sz = 1e4 + 10;
const ll mod = 1e9 + 7;

int t, cs;
int n, m;
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};
char direction[] = "ENSW";
char maze[13][13];
int nextMove[13][13][4][2];
bool vis[13][13];
bool inMaze(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

bool check(int x, int y) {
    if (!inMaze(x, y)) {
        return true;
    }
    if (vis[x][y]) {
        return false;
    }
    vis[x][y] = true;
    bool ret = false;;
    for (int d = 0; d < 4; d++) {
        ret |= check(nextMove[x][y][d][0], nextMove[x][y][d][1]);
    }
    return ret;
}
bool possible(vector <pair<int, int>> &possiblePositions) {
    bool ret = true;
    for (int d = 0; d < 4; d++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (maze[i][j] != '.')  {
                   continue;
                }
                memset(vis, 0, sizeof vis);
                ret &= check(i, j);
                possiblePositions.push_back(make_pair(i, j));
            }
        }
    }
    return ret;
}

string bfs(vector <pair<int, int>> v) {
    string ans;
    queue <vector<pair<int, int>>> q;
    q.push(v);
    map <vector <pair<int, int>>, string> mp;
    vector <pair<int, int>> u;
    mp[v] = "*";
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            v.clear();
            for (pair<int, int> it: u) {
                int x = it.first;
                int y = it.second;
                int nx = nextMove[x][y][d][0];
                int ny = nextMove[x][y][d][1];
                if (inMaze(nx, ny)) {
                    v.push_back(make_pair(nx, ny));
                }
            }
            sort(v.begin(), v.end());
            v.resize(unique(v.begin(), v.end()) - v.begin());
            if (mp[v].empty()) {
                mp[v] = mp[u] + direction[d];
                q.push(v);
            }
            if (v.empty()) {
                ans = mp[v];
                return ans;
            }
        }
    }
    return ans;
}

void solve() {
    printf("Case %d: ", cs);
    vector <pair<int, int>> possiblePositions;
    if (possible(possiblePositions)) {
        printf("%s\n", bfs(possiblePositions).c_str() + 1);
        return;
    }
    printf("Impossible\n");
}

void process(int x, int y, int d) {
    if (nextMove[x][y][d][0] != -1) {
        return;
    }
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (!inMaze(nx, ny)) {
        nextMove[x][y][d][0] = nx;
        nextMove[x][y][d][1] = ny;
    }
    else if (maze[nx][ny] == '#') {
        nextMove[x][y][d][0] = x;
        nextMove[x][y][d][1] = y;
    }
    else {
        process(nx, ny, d);
        nextMove[x][y][d][0] = nextMove[nx][ny][d][0];
        nextMove[x][y][d][1] = nextMove[nx][ny][d][1];
    }
}

void preprocess() {
    memset(nextMove, -1, sizeof nextMove);
    for (int d = 0; d < 4; d++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (maze[i][j] != '.') {
                    continue;
                }
                process(i, j, d);
            }
        }
    }
}

int main() {

    scanf("%d", &t);

    for (cs = 1; cs <= t; cs++) {
        
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            scanf("%s", &maze[i][1]);
        }

        preprocess();

        solve();
    }

    return 0;
}