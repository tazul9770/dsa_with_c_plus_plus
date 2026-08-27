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
    vector<int> adj[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mt[i][j] == 1 && i != j) {
                adj[i].push_back(j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int child : adj[i]) {
            cout << child << " ";
        }
        cout << endl;
    }
    return 0;
}