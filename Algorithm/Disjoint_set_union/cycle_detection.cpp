#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
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
    if(sz[leaderA] > sz[leaderB]) {
        par[leaderB] = leaderA;
        sz[leaderA] += leaderB;
    } else {
        par[leaderA] = leaderB;
        sz[leaderB] += leaderA;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    bool cycle = false;
    while(e--) {
        int a, b;
        cin >> a >> b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);
        if(leader1 == leader2) {
            cycle = true;
        } else {
            dsu_union_by_size(a, b);
        }
    }
    if(cycle) {
        cout << "Cycle found" << endl;
    } else {
        cout << "Cycle not found" << endl;
    }
    return 0;
}