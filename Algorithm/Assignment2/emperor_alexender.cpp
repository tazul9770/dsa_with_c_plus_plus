#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
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
    int u, v;
    long long w;
    Edge(int u, int v, long long w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, e;
    cin >> n >> e;
    
    dsu_initialize(n);
    
    vector<Edge> edges;
    
    for(int i = 0; i < e; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    
    sort(edges.begin(), edges.end(), cmp);

    long long totalCost = 0;
    int edgeCount = 0;

    for(Edge ed : edges) {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);
        
        if(leaderA == leaderB) {
            continue;
        } else {
            dsu_union(ed.u, ed.v);
            totalCost += ed.w;
            edgeCount++;
        }
    }
    
    if(edgeCount != n - 1) {
        cout << "Not Possible" << endl;
    } else {
        int badEdges = e - (n - 1); 
        cout << badEdges << " " << totalCost << endl;
    }
    
    return 0;
}
