#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
int par[N];
bool ans;

void bfs(int src) {
    queue<int> q;
    vis[src] = true;
    q.push(src);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int child : adj[p]) {
            if(vis[child] == true && par[p] != child) {
                ans = true;
            }
            if(vis[child] == false) {
                q.push(child);
                par[child] = p;
                vis[child] = true;
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(par, -1, sizeof(par));
    memset(vis, false, sizeof(vis));
    ans = false;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            bfs(i);
        }
    }
    if(ans) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "Cycle not detected" << endl;
    }
    return 0;
}