#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
bool pathVis[N];
bool ans;

void dfs(int src) {
    vis[src] = true;
    pathVis[src] = true;
    for(int child : adj[src]) {
        if(pathVis[child]) {
            ans = true;
        }
        if(!vis[child]) {
            dfs(child);
        }
    }
    pathVis[src] = false;
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));
    ans = false;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    if(ans) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "Cycle not detected" << endl;
    }
    return 0;
}