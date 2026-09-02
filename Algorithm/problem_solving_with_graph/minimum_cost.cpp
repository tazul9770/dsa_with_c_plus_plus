#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int par[N];
int sz[N];

void dsu_initialize(int n) {
    for(int i = 0; i < n; i++) {
        par[i] = -1;
        sz[i] = 1;
    }
}

int dsu_find(int node) {
    if(par[node] == -1) {
        return node;
    }
    int x = dsu_find(par[node]);
    par[node] = x;
    return x;
}

void dsu_union_by_size(int node1, int node2) {
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(sz[leaderA] >= sz[leaderB]) {
        par[leaderB] = leaderA;
        sz[leaderA] += leaderB;
    } else {
        par[leaderA] = leaderB;
        sz[leaderB] += leaderA;
    }
}

class Edge {
    public:
        int u, v, c;
        Edge(int u, int v, int c) {
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
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    int totalCost = 0;

    for(Edge ed : edgeList) {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);
        if(leaderA == leaderB) {
            continue;
        } else {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.c;
        }
    }

    cout << totalCost << endl;
    
    return 0;
}