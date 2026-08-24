#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> mt1;
vector<vector<char>> mt2;
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

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    vis[si][sj] = true;
    q.push({si, sj});
    while(!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        if(mt1[a][b] == '0') {
            flag = false;
        }
        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && mt2[ci][cj] == '1') {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}


int main() {
    cin >> n >> m;
    mt1.resize(n, vector<char>(m));
    mt2.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt1[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt2[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && mt2[i][j] == '1') {
                flag = true;
                bfs(i, j);
                if(flag == true) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}