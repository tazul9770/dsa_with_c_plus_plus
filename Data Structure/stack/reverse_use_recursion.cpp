#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    stack<int> newSt;
    while(!s.empty()) {
        newSt.push(s.top());
        s.pop();
    }
    s.push(x);
    while(!newSt.empty()) {
        s.push(newSt.top());
        newSt.pop();
    }
}

int main() {
    stack<int> s;

    while (true) {
        int n;
        cin >> n;

        if (n == -1) {
            break;
        }

        s.push(n);
    }

    stack<int> item = s;

    cout << "Before reverse: ";
    while (!item.empty()) {
        cout << item.top() << " ";
        item.pop();
    }

    cout << endl;

    reverseStack(s);

    cout << "After reverse: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}