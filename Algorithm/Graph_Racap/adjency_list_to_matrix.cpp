#include <bits/stdc++.h>
using namespace std;
void convert(int n, vector<int> adj[]) {
    int mt[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mt[i][j] = 0;
            if(i == j) mt[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j : adj[i]) {
            mt[i][j] = 1;
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
    vector<int> adj[n];
    while(e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    convert(n, adj);
    return 0;
}