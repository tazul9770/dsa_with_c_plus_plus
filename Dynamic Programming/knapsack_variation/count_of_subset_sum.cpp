#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int subset_sum(int n, int ara[], int s) {
    if(n == 0) {
        if(s == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if(dp[n][s] != -1) {
        return dp[n][s];
    }

    if(ara[n-1] <= s) {
        int op1 = subset_sum(n-1, ara, s-ara[n-1]);
        int op2 = subset_sum(n-1, ara, s);
        return dp[n][s] = op1 + op2;
    } else {
        int op2 = subset_sum(n-1, ara, s);
        return dp[n][s] = op2;
    }
}
int main() {
    int n;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    int s;
    cin >> s;

    memset(dp, -1, sizeof(dp));

    cout << subset_sum(n, ara, s) << endl;

    return 0;
}