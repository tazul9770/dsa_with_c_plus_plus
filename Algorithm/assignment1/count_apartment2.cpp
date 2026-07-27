#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> mt;
vector<vector<bool>> visited;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

int bfs(int src1, int src2) {
    queue<pair<int, int>> q;
    q.push({src1, src2});
    visited[src1][src2] = true;
    int room = 0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        room++;
        for(int i = 0; i < 4; i++) {
            int c1 = x + d[i].first;
            int c2 = y + d[i].second;
            if(valid(c1, c2) == true && mt[c1][c2] == '.' && visited[c1][c2] == false) {
                q.push({c1, c2});
                visited[c1][c2] = true; 
            }
        }
    }
    return room;
}
int main() {
    cin >> n >> m;
    mt.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mt[i][j] == '.' && visited[i][j] == false) {
                int x = bfs(i, j);
                v.push_back(x);
            }
        }
    }
    
    sort(v.begin(), v.end());
    if(v.size() == 0) {
        cout << "0" << endl;
    }
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
