#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s) {
    stack<char> st;
    for(char c : s) { 
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) {
                return false;
            } else {
                if(c == ')' && st.top() == '(') {
                    st.pop();
                } else if(c == '}' && st.top() == '{') {
                    st.pop();
                } else if(c == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
    }
    if(st.empty()) {
        return true;
    } else {
        return false;
    }
}
int main() {
    string s;
    cin >> s;
    if(is_valid(s)) {
        cout << "Valid parenthesis" << endl;
    } else {
        cout << "Not valid parenthesis" << endl;
    }
    return 0;
}