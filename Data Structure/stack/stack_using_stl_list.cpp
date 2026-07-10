#include <bits/stdc++.h>
using namespace std;

class myStack {
    public:
    list<int> l;
    void push(int val) {
        l.push_back(val);
    }
    void pop() {
        l.pop_back();
    }
    int top() {
        return l.back();
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