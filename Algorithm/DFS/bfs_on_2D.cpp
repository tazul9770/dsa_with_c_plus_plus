#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005; 
int n, m;
char ara[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty()) {
        auto par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;

        cout << a << " " << b << " -> distance: " << dis[a][b] << endl;

        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ara[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    if(!valid(si, sj)) {
        cout << "Invalid start position!" << endl;
        return 0;
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);

    return 0;
}
