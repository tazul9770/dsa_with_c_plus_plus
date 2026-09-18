#include<bits/stdc++.h>
using namespace std;

int dp[100002];
int input;

bool find(int n) {
    if(n > input) {
        return false;
    }
    if(n == input) {
        return true;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    bool pick = find(n+3) || find(n*2);
    return dp[n] = pick;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> input;
        memset(dp, -1, sizeof(dp));
        if(find(1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}