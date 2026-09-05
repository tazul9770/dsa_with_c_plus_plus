#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5; 
char mt[N][N];
bool vis[N][N];
int n, m;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; 

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    
    pair<int, int> parent[N][N]; 

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;

        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj]  && mt[ci][cj] != '#') {
                vis[ci][cj] = true;
                q.push({ci, cj});
                parent[ci][cj] = {a, b};

                if(mt[ci][cj] == 'D') {
                    pair<int, int> curr = {ci, cj};
                    while(curr != make_pair(si, sj)) {
                        if(mt[curr.first][curr.second] != 'R' && mt[curr.first][curr.second] != 'D') {
                            mt[curr.first][curr.second] = 'X';
                        }
                        curr = parent[curr.first][curr.second];
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int si, sj; 
    int di, dj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt[i][j];
            if(mt[i][j] == 'R') {
                si = i;
                sj = j;
            }
            if(mt[i][j] == 'D') {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bfs(si, sj);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mt[i][j];
        }
        cout << endl;
    }

    return 0;
}
