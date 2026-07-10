#include <bits/stdc++.h>
using namespace std;

void insertVal(stack<int> &st, int x) {
    stack<int> newSt;
    while(!st.empty()) {
        newSt.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!newSt.empty()) {
        st.push(newSt.top());
        newSt.pop();
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    stack<int> s;
    while(true) {
        int x;
        cin >> x;
        if(x == -1) {
            break;
        }
        s.push(x);
    }
    int n;
    cin >> n;
    insertVal(s, n);
    return 0;
}