#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mt[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mt[i][j];
        }
    }
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mt[i][j] > 1) {
                adj[i].push_back({j, mt[i][j]});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(pair<int, int> child : adj[i]) {
            cout << "{" << child.first << " , " << child.second << "}";
        }
        cout << endl;
    }
    return 0;
}