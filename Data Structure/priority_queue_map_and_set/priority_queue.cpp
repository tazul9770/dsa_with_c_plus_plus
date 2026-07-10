#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> pq;
    // min heap priority queue declare
    priority_queue<int, vector<int>, greater<int>> q;
    while(true) {
        int c;
        cin >> c;
        if(c == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else if(c == 2) {
            pq.pop();
        } else if(c == 3) {
            cout << pq.top() << endl;
        } else {
            break;
        }
    }
    return 0;
}