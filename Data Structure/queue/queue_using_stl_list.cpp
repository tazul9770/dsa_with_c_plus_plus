#include <bits/stdc++.h>
using namespace std;

class myQueue {
    public:
    list<int> l;
    void push(int val) {
        l.push_back(val);
    }
    void pop() {
        l.pop_front();
    }
    int front() {
        return l.front();
    }
    int size() {
        return l.size();
    }
    bool empty() {
        if(l.size() == 0) {
            return true;
        } else {
            return false;
        }
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