#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool vis[N];
int dis[N];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int child : adj[p]) {
            if(vis[child] == false) {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[p]+1;
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
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int src, des, k;
    cin >> src >> des >> k;
    bfs(src);
    cout << dis[des] << endl;
    if(dis[des] != -1 && dis[des] <= k*2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
