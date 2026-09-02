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
    int x = dsu_find(par[node]);
    par[node] = x;
    return x;
}

void dsu_union_by_size(int node1, int node2) {
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(sz[leaderA] >= sz[leaderB]) {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    } else {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}

int main() {
    int n;
    cin >> n;
    dsu_initialize(n);
    vector<pair<int, int>> del;
    vector<pair<int, int>> create;
    for(int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        int L1 = dsu_find(a);
        int L2 = dsu_find(b);
        if(L1 == L2) {
            del.push_back({a, b});
        } else {
            dsu_union_by_size(a, b);
        }
    }
    cout << del.size() << endl;
    for(int i = 2; i <= n-1; i++) {
        int L1 = dsu_find(1);
        int L2 = dsu_find(i);
        if(L1 != L2) {
            create.push_back({1, i});
            dsu_union_by_size(1, i);
        }
    }
    for(int i = 0; i < del.size(); i++) {
        cout << del[i].first << " " << del[i].second << " " << create[i].first << " " << create[i].second << endl;
    }
    return 0;
}