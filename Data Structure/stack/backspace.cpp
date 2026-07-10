#include <bits/stdc++.h>
using namespace std;

bool backspace(string s, string t) {
    stack<char> s1, s2;
    for(char c : s) {
        if(c == '#') {
            if(!s1.empty()) {
                s1.pop();
            }
        } else {
            s1.push(c);
        }
    }

    for(char c : t) {
        if(c == '#') {
            if(!s2.empty()) {
                s2.pop();
            }
        } else {
            s2.push(c);
        }
    }

    return s1 == s2;
}
int main() {
    string s, t;
    cin >> s >> t;
    if(backspace(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}