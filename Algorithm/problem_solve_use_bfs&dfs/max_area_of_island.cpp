#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> mt;
vector<vector<bool>> vis;

int ans;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

void dfs(int si, int sj) {
    vis[si][sj] = true;
    ans++;
    for(int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && mt[ci][cj] == 1) {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;
    mt.resize(n, vector<int>(m));
    vis.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    int mx = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && mt[i][j] == 1) {
                ans = 0;
                dfs(i, j);
                mx = max(ans, mx);
            }
        }
    }

    cout << mx << endl;

    return 0;
}