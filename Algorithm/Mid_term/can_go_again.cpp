#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const long long INF = 1e18;
const int N = 1e5+5;
long long dis[N];

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edgeList;
    for (int i = 0; i < e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }
    int src;
    cin >> src;
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dis[src] = 0;
    
    for (int i = 1; i <= n - 1; i++) {
        for (Edge ed : edgeList) {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] != INF && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool ans = false;
    for(Edge ed : edgeList) {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if (dis[u] != INF && dis[u] + c < dis[v]) {
            ans = true;
            break;
        }
    }
    if(ans == true) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }
    
    int t;
    cin >> t;

    while (t--) {
        int d;
        cin >> d;
        
        if(dis[d] == INF) {
            cout << "Not Possible" << endl;
        } else {
            cout << dis[d] << endl;
        }
    }
    return 0;
}
