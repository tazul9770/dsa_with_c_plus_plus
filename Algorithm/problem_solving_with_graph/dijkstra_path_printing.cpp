#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const long long int INF = 1e18;
long long int dis[N];
int parent[N];
vector<pair<int, int>> v[N];

class cmp {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
};

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    dis[src] = 0;
    q.push({src, dis[src]});
    while(!q.empty()) {
        pair<int, int> par = q.top();
        q.pop();
        int node = par.first;
        int cost = par.second;
        for(pair<int, int> child : v[node]) {
            int childNode = child.first;
            int childCost = child.second;
            if(cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
                parent[childNode] = node;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 1; i <= n; i++) {
        dis[i] = INF;
        parent[i] = -1;
    }
    dijkstra(1);
    int x = n;
    vector<int> vc;
    while(x != -1) {
        vc.push_back(x);
        x = parent[x];
    }
    reverse(vc.begin(), vc.end());
    for(int val : vc) {
        cout << val << " ";
    }
    return 0;
}