#include <bits/stdc++.h> 
using namespace std;
int main() {
    list<int> myList;
    int q;
    cin >> q;
    while(q--) {
        int pos, val;
        cin >> pos >> val;
        if(pos == 0) {
            myList.push_front(val);
        } else if(pos == 1) {
            myList.push_back(val);
        } else if(pos == 2) {
            if(val >= 0 && val < myList.size()) {
                auto it = myList.begin();
                advance(it, val);
                myList.erase(it);
            }
        }
        cout << "L -> ";
        for (auto it = myList.begin(); it != myList.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        cout << "R -> ";
        for (auto it = myList.rbegin(); it != myList.rend(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}