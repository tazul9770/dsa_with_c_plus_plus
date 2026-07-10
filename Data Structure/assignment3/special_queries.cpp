#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    queue<string> q;
    while(t--) {
        int num;
        string name;
        cin >> num;
        if(num == 0) {
            cin >> name;
            q.push(name);
        } else if(num == 1) {
            if(q.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
    return 0;
}