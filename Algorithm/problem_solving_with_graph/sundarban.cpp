#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> mt;
vector<vector<bool>> vis;
vector<vector<int>> dis;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n) {
        return false;
    } else {
        return true;
    }
}

void bfs(int si, int sj) {
    vis[si][sj] = true;
    queue<pair<int, int>> q; 
    q.push({si, sj});
    dis[si][sj] = 0;

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;

        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && (mt[ci][cj] == 'P' || mt[ci][cj] == 'E')) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}

int main() {
    cin >> n;
    mt.resize(n, vector<char>(n));
    vis.resize(n, vector<bool>(n, false));
    dis.resize(n, vector<int>(n, -1));

    int si, sj, di, dj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mt[i][j];
            if(mt[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if(mt[i][j] == 'E') {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);
    cout << dis[di][dj] << endl;
    return 0;
}
