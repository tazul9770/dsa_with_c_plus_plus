#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;
    int mt[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mt[i][j] = 0;
            if(i == j) mt[i][j] = 1;
        }
    }
    while(e--) {
        int a, b;
        cin >> a >> b;
        mt[a][b] = 1;
        mt[b][a] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mt[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}