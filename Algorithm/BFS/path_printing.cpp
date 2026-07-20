#include <bits/stdc++.h>
using namespace std;
vector<int> v[105];
bool vis[105];
int level[105];
int par[105];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(auto child : v[p]) {
            if(vis[child] == false) {
                q.push(child);
                vis[child] = true;
                level[child] = level[p] + 1;
                par[child] = p;
            }
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    while(e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src, des;
    cin >> src >> des;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(par, -1, sizeof(par));
    bfs(src);
    int x = des;
    vector<int> path;
    while(x != -1) {
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    for(auto v : path) {
        cout << v << " ";
    }
    return 0;
}