#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> mt;
vector<vector<bool>> vis;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

bool flag;

void dfs(int si, int sj) {
    vis[si][sj] = true;
    if(si == 0 || si == n-1 || sj == 0 || sj == m-1) {
        flag = false;
    }
    for(int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && mt[ci][cj] == 0) {
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

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && mt[i][j] == 0) {
                flag = true;
                dfs(i, j);
                if(flag == true) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}