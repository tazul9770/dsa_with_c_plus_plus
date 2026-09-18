#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ara[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
        sum += ara[i];
    }
    bool dp[n+1][sum+1];
    dp[0][0] = true;
    for(int i = 1; i <= sum; i++) {
        dp[0][i] = false;
    }
    for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(ara[i-1] <= j) {
                    bool op1 = dp[i-1][j-ara[i-1]];
                    bool op2 = dp[i-1][j];
                    dp[i][j] = op1 || op2;
                } else {
                   bool op2 = dp[i-1][j];
                   dp[i][j] = op2; 
                }
            }
        }

    vector<int> v;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(dp[i][j] == 1) {
                v.push_back(j);
            }
        }
    }

    int ans = INT_MAX;
    for(int val : v) {
        int s1 = val;
        int s2 = sum - s1;
        ans = min(ans, abs(s1 - s2));
    }

    cout << ans << endl;
    return 0;
}