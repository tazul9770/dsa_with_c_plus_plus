// All pairs shortest path ber korte pare & negative cycle detect korte pare

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    int n, e;
    cin >> n >> e;

    long long adj[105][105]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = INF;
            if (i == j) adj[i][j] = 0;
        }
    }

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], (long long)c); 
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((adj[i][k] < INF && adj[k][j] < INF) && (adj[i][k] + adj[k][j] < adj[i][j])) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
        
    }

    bool hasNegativeCycle = false;
    for (int i = 0; i < n; i++) {
        if (adj[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Negative cycle detected!" << endl;
    } else {
        cout << "All-pairs shortest path matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == INF) cout << "INF ";
                else cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
