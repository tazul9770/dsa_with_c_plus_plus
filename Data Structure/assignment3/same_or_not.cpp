#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> s;
    queue<int> q;
    int n, m;
    cin >> n >> m;
    while(n--) {
        int val;
        cin >> val;
        s.push(val);
    }
    while(m--) {
        int val;
        cin >> val;
        q.push(val);
    }
    if(s.size() != q.size()) {
        cout << "NO" << endl;
    } else {
        bool flag = true;
        while(!s.empty()) {
            if(s.top() != q.front()) {
                flag = false;
                break;
            }
            s.pop();
            q.pop();
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}