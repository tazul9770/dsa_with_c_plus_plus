#include <bits/stdc++.h>
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
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    while(e--) {
        int a, b;
        cin >> a >> b;
        int l1 = dsu_find(a);
        int l2 = dsu_find(b);
        if(l1 != l2) {
            dsu_union_by_size(a, b);
        }
    }
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        v.push_back(dsu_find(i));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size()-1 << endl;
    for(int i = 0; i < v.size()-1; i++) {
        cout << v[i] << " " << v[i+1] << endl;
    }
    return 0;
}