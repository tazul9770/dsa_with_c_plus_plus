#include <bits/stdc++.h>
using namespace std;
const int x = 100;
bool vis[x][x];
int dis[x][x];
int n, m;
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

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
        pair<int, int> par = q.front();
        int a = par.first; 
        int b = par.second;
        q.pop();
        
        for(pair<int, int> move : d) {
            int ci = a + move.first;
            int cj = b + move.second;
            
            if(valid(ci, cj) == true && vis[ci][cj] == false) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        
        int Ki, Kj;
        cin >> Ki >> Kj;
        
        int Qi, Qj;
        cin >> Qi >> Qj;
        
        bfs(Ki, Kj);
        
        cout << dis[Qi][Qj] << endl;
    }
    return 0;
}
