#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

void bfs(int src, int n, int dis[]) {
    for(int i = 0; i < n; i++){
        dis[i] = -1;
    }
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int v : adj[p]) {
            if(dis[v] == -1) {
                dis[v] = dis[p] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n, e;
        cin >> n >> e;
        adj.assign(n, {});  
        while(e--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int src, des;
        cin >> src >> des;

        int dist_s[n], dist_d[n];
        bfs(src, n, dist_s); 
        bfs(des, n, dist_d);  

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dist_s[i] + dist_d[i]);
        }

        cout << "Case " << tc << ": " << ans << "\n";
    }
    return 0;
}
