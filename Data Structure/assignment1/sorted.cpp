// age theke sort thakle print "yes", na thakle "no"
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        int ara[n];
        for(int i = 0; i < n; i++) {
            cin >> ara[i];
        }
        bool found = true;
        for(int i = 0; i < n-1; i++) {
            if(ara[i] > ara[i+1]) {
                found = false;
                break;
            }
        }
        if(found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

