#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> st;
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