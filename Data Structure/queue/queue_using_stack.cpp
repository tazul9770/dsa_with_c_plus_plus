#include <bits/stdc++.h>
using namespace std;

class myQueue {
    public:
    stack<int> s;

    void push(int val) {
        s.push(val);
    }

    void pop() {
        stack<int> s2;
        int last;
        while(!s.empty()) {
            int k = s.top();
            s.pop();
            if(s.empty()) {
                last = k;
                break;
            }
            s2.push(k);
        }
        while(!s2.empty()) {
            s.push(s2.top());
            s2.pop();
        }
    }

    int front() {
        stack<int> s2;
        int last;
        while(!s.empty()) {
            int k = s.top();
            s.pop();
            if(s.empty()) {
                last = k;
            }
            s2.push(k);
        }
        while(!s2.empty()) {
            s.push(s2.top());
            s2.pop();
        }
        return last;
    }

    int size() {
        return s.size();
    }

    bool empty() {
        return s.empty();
    }
};
int main() {
    myQueue q;
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