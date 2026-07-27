#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;
    int mt[1003][1003];
    memset(mt, 0, sizeof(mt));
    while(e--) {
        int a, b;
        cin >> a >> b;
        mt[a][b] = 1;
    }
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(mt[x][y] == 1 || x == y) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}