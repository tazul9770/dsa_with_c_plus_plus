#include <bits/stdc++.h>
using namespace std;
void convert(int n, vector<pair<int, int>> adj[]) {
    int mt[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mt[i][j] = -1;
            if(i == j) mt[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(pair<int, int> child : adj[i]) {
            int node = child.first;
            int cost = child.second;
            mt[i][node] = cost;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mt[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    vector<pair<int,int>> adj[n];
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    convert(n, adj);
    return 0;
}