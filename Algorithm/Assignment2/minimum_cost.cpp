#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int par[N];
int sz[N];

void dsu_initialize(int n) {
    for(int i = 1; i <= n; i++) {
        par[i] = -1;
        sz[i] = 1;
    }
}

int dsu_find(int node) {
    if(par[node] == -1) {
        return node;
    }
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2) {
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if(sz[leader1] > sz[leader2]) {
        par[leader2] = leader1;
        sz[leader1] = sz[leader1] + sz[leader2];
    } else {
        par[leader1] = leader2;
        sz[leader2] = sz[leader2] + sz[leader1];
    }
}

class Edge {
    public:
        long long int u, v, c;
        Edge(long long int u, long long int v, long long int c) {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};

bool cmp(Edge a, Edge b) {
    return a.c < b.c;
}

int main() {
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> edgeList;

    while(e--) {
        long long int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);
    long long int minCost = 0;
    int edgeCount = 0;

    for(Edge ed : edgeList) {
        int L1 = dsu_find(ed.u);
        int L2 = dsu_find(ed.v);
        if(L1 == L2) {
            continue;
        } else {
            dsu_union(ed.u, ed.v);
            minCost = minCost + ed.c;
            edgeCount++;
        }
    }
    if(edgeCount == n-1) {
        cout << minCost << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}