#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> mt;
vector<vector<bool>> vis;

vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    } else {
        return true;
    }
}

bool dfs(int Si, int Sj, int Di, int Dj) {
    if(Si == Di && Sj == Dj) {
        return true;
    }
    vis[Si][Sj] = true;
    for(int i = 0; i < 4; i++) {
        int c1 = Si + d[i].first;
        int c2 = Sj + d[i].second;
        if(valid(c1, c2) && !vis[c1][c2] && mt[c1][c2] == '.') {
            if(dfs(c1, c2, Di, Dj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    mt.resize(n, vector<char> (m));
    vis.resize(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }
    int Si, Sj, Di, Dj;
    cin >> Si >> Sj >> Di >> Dj;
    if(mt[Si][Sj] == '.' && mt[Di][Dj] == '.') {
        if(dfs(Si, Sj, Di, Dj)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return  0;
}