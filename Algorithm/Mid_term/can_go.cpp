#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const int N = 100005;
int n, e;
vector<pair<int, int>> adj[N];
long long dis[N];

class cmp {
    public:
        bool operator()(pair<int, long long> a, pair<int, long long> b) {
            return a.second > b.second;
        }
};

void dijkstra(int src) {
    for(int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> q;
    q.push({src, 0});
    dis[src] = 0;
    while(!q.empty()) {
        pair<int, long long> par = q.top();
        q.pop();
        int node = par.first;
        long long cost = par.second;
        for(pair<int, int> child : adj[node]) {
            int childNode = child.first;
            int childCost = child.second;
            if(cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                q.push({childNode, cost + childCost});
            }
        }
    }
}

int main() {
    cin >> n >> e;
    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src, t;
    cin >> src;
    dijkstra(src);
    cin >> t;
    while(t--) {
        int d, cost;
        cin >> d >> cost;
        if(dis[d] <= cost) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}