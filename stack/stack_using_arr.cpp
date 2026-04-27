#include <bits/stdc++.h>
using namespace std;

class myStack {
    public:
    vector<int> v;
    void push(int val) {
        v.push_back(val);
    }
    void pop() {
        v.pop_back();
    }
    int top() {
        return v.back();
    }
    int size() {
        return v.size();
    }
    bool empty() {
        if(v.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    myStack st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // cout << st.top() << endl;
    // st.pop();
    // cout << st.top() << endl;

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