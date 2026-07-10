#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;
    vector<int> mt[n];
    while(e--) {
        int a, b;
        cin >> a >> b;
        mt[a].push_back(b);
        mt[b].push_back(a);
    }
    // akhane 1 index er sathe k k connect ache ta ber kortechi
    for(int i = 0; i < mt[1].size(); i++) {
        cout << mt[1][i] << " ";
    }
    return 0;
}