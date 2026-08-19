#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dis[N];

class Edge {
    public:
        int u, v, c;
        Edge(int u, int v, int c) {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edgeList;
    while(e--) {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }

    for(int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
    }

    int src;
    cin >> src;
    dis[src] = 0;

    for(int i = 1; i <= n-1; i++) {
        for(Edge edge: edgeList) {
            int u = edge.u;
            int v = edge.v;
            int c = edge.c;
            if(dis[u] < INT_MAX && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for(Edge edge: edgeList) {
        int u = edge.u;
        int v = edge.v;
        int c = edge.c;
        if(dis[u] < INT_MAX && dis[u] + c < dis[v]) {
            cycle = true;
            break;
        }
    }

    if(cycle) {
        cout << "Negative cycle detected" << endl;
    } else {
        cout << "Not detected" << endl;
    }

    return 0;
}