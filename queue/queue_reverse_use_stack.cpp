#include <bits/stdc++.h>
using namespace std;

queue<int> reverse(queue<int> &q){
    stack<int> s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    return q;
}

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

    queue<int> ans = reverse(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}