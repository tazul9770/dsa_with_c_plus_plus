#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
int par[N];
bool ans;

void dfs(int src) {
    vis[src] = true;
    for(int child : adj[src]) {
        if(vis[child] && par[src] != child) {
            ans = true;
        }
        if(!vis[child]) {
            par[child] = src;
            dfs(child);
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