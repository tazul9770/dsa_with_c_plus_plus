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
    vector<pair<int, int>> edgeList;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mt[i][j] == 1 && i != j) {
                edgeList.push_back({i, j});
            }
        }
    }
    for(pair<int, int> child : edgeList) {
        cout << child.first << " " << child.second << endl;
    }
    return 0;
}