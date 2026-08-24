#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> vis; 
int ans = 0;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    vis[si][sj] = true;
    q.push({si, sj});
    while(!q.empty()) {
        auto par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if(valid(ci, cj)) {
                if(grid[ci][cj] == 0) {
                    ans++;
                }
            } else {
                ans++;
            }
            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1) {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    vis.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
