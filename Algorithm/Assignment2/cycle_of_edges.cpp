#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
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
    int x = dsu_find(par[node]);
    par[node] = x;
    return x;
}

void dsu_union(int node1, int node2) {
    int L1 = dsu_find(node1);
    int L2 = dsu_find(node2);
    if(sz[L1] > sz[L2]) {
        par[L2] = L1;
        sz[L1] += sz[L2];
    } else {
        par[L1] = L2;
        sz[L2] += sz[L1];
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    int edge = 0;
    while(e--) {
        int a, b;
        cin >> a >> b;
        int L1 = dsu_find(a);
        int L2 = dsu_find(b);
        if(L1 == L2) {
            edge++;
        } else {
            dsu_union(a, b);
        }
    }
    cout << edge << endl;
    return 0;
}