#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int par[N];
int sz[N];
int level[N];

void dsu_initialize(int n) {
    for(int i = 0; i < n; i++) {
        par[i] = -1;
        sz[i] = 1;
        level[i] = 0;
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
        sz[leaderB] = leaderA;
        sz[leaderA] += leaderB;
    } else {
        sz[leaderA] = leaderB;
        sz[leaderB] += leaderA;
    }
}

void dsu_union_by_rank(int node1, int node2) {
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(level[leaderA] > level[leaderB]) {
        par[leaderB] = leaderA;
    } else if(level[leaderB] > level[leaderA]) {
        par[leaderA] = leaderB;
    } else {
       par[leaderA] = leaderB;
       level[leaderB]++; 
    }
}

int main() {
    dsu_initialize(6);
    dsu_union_by_size(1, 2);
    dsu_union_by_size(3, 4);
    cout << dsu_find(1);
    return 0;
}