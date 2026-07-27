#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    while(e--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int q;
    cin >> q;
    while(q--) {
        int a;
        cin >> a;
        vector<int> v = adj[a];
        if(v.size() == 0) {
            cout << "-1";
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}