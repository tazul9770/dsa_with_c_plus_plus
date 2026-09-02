#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
int par[N];
bool vis[N];

void dijkstra(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int child : v[p]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
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
    memset(par, -1, sizeof(par));
    memset(vis, false, sizeof(vis));
    dijkstra(1);
    int x = n;
    vector<int> path;
    while(x != -1) {
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    if(path.size() == 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << path.size() << endl;
        for(int i : path) {
            cout << i << " ";
        }
    }
    return 0;
}