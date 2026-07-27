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
void dfs(int src1, int src2) {
    visited[src1][src2] = true;
    for (int i = 0; i < 4; i++) {
        int c1 = src1 + d[i].first;
        int c2 = src2 + d[i].second;
        
        if (valid(c1, c2) && visited[c1][c2] == false && (mt[c1][c2] == '.' || mt[c1][c2] == 'B')) {
            dfs(c1, c2);
        }
    }
}

int main() {
    cin >> N >> M;
    mt.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    int a1, a2;
    int b1, b2;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mt[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mt[i][j] == 'A') {
                a1 = i;
                a2 = j;
            }
            if(mt[i][j] == 'B') {
                b1 = i;
                b2 = j;
            }
        }
    }
    dfs(a1, a2);
    if(visited[b1][b2] == true) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

