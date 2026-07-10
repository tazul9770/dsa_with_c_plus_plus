#include<bits/stdc++.h> //0011
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        stack<char> s;
        for(char c : str) {
            if(c == '0' || c == '1') {
                if(!s.empty() && c == '0' && s.top() == '1') {
                    s.pop();
                } else if(!s.empty() && c == '1' && s.top() == '0') {
                    s.pop();
                } else {
                    s.push(c);
                }
            }
        }
        if(s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}