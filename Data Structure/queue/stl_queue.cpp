#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q;
    while(true) {
        int n;
        cin >> n;
        if(n == -1) {
            break;
        }
        q.push(n);
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}