#include <bits/stdc++.h>
using namespace std;

class myStack {
    public:
    queue<int> q;

    void push(int val) {
        q.push(val);
    }

    void pop() {
        queue<int> newQ;
        int last;
        while(!q.empty()) {
            int k = q.front();
            q.pop();
            if(q.empty()) {
                last = k;
                break;
            }
            newQ.push(k);
        }
        q = newQ;
    }

    int top() {
        queue<int> newQ;
        int last;
        while(!q.empty()) {
            int k = q.front();
            q.pop();
            if(q.empty()) {
                last = k;
            }
            newQ.push(k);
        }
        q = newQ;
        return last;
    }

    int size() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }
};
int main() {
    myStack st;
    
    while(true) {
        int n;
        cin >> n;
        if(n == -1) {
            break;
        }
        st.push(n);
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}