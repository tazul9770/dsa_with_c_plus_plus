#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<char>> mt;
vector<vector<bool>> visited;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j) {
    if(i < 0 || i >= N || j < 0 || j >= M) {
        return false;
    } else {
        return true;
    }
}
void bfs(int src1, int src2) {
    visited[src1][src2] = true;
    queue<pair<int, int>> q;
    q.push({src1, src2});
    while(!q.empty()) {
        auto par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if(valid(ci, cj) && mt[ci][cj] == '.' && !visited[ci][cj]) {
                q.push({ci, cj});
                visited[ci][cj] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    mt.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mt[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mt[i][j] == '.' && visited[i][j] == false) {
                count++;
                bfs(i, j);
            }
        }
    }

    cout << count << endl;
    return 0;
}
