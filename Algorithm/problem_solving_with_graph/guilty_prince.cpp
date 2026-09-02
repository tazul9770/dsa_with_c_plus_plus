#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<char>> mt;
vector<vector<bool>> vis;
int cnt;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

void dfs(int si, int sj) {
    vis[si][sj] = true;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && (mt[ci][cj] == '.' || mt[ci][cj] == '@')) {
            dfs(ci, cj);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        cin >> m >> n;
        mt.assign(n, vector<char>(m));
        vis.assign(n, vector<bool>(m, false));

        int si, sj;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mt[i][j];
                if(mt[i][j] == '@') {
                    si = i;
                    sj = j;
                }
            }
        }

        cnt = 0;
        dfs(si, sj);
        cout << "Case " << k << ": " << cnt << endl;
    }
    return 0;
}
