#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> mt;
vector<vector<bool>> vis;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

int bfs(int si, int sj) {
    queue<pair<int, int>> q;
    vis[si][sj] = true;
    q.push({si, sj});
    int count = 1;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;
        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && mt[ci][cj] == '.') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> m;
    mt.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    bool flag = false;
    int mn = INT_MAX;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mt[i][j] == '.' && !vis[i][j]) {
                flag = true;
                int cnt = bfs(i, j);
                mn = min(mn, cnt);
            }
        }
    }

   if (flag) {
        cout << mn << endl;
    } else {
        cout << -1 << endl; 
    }

    return 0;
}