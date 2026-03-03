//2 ta array thakbe , next ekta index input ashbe 2nd array ta k index er por insert korte hobe
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int x;
    cin >> x;

    vector<int> ans;

    for(int i = 0; i < x; i++) {
        ans.push_back(a[i]);
    }

    for(int i = 0; i < m; i++) {
        ans.push_back(b[i]);
    }

    for(int i = x; i < n; i++) {
        ans.push_back(a[i]);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}