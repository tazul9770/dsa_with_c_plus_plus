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
int main() {
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edge[n];
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    vector<Edge> edgeList;
    for(int i = 0; i < n; i++) {
        for(pair<int, int> child : edge[i]) {
            int node = child.first;
            int cost = child.second;
            edgeList.push_back(Edge(i, node, cost));
        }
    }
    for(Edge ed : edgeList) {
        cout << ed.u << " " << ed.v << " " << ed.c << endl;
    }
    return 0;
}