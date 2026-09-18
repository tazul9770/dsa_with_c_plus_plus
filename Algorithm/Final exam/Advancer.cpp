#include <bits/stdc++.h>
using namespace std;

int dp[1003][1003];

int knapsack(int n, int weight[], int val[], int w) {
    if(n == 0 || w == 0) {
        return 0;
    }

    if(dp[n][w] != -1) {
        return dp[n][w];
    }

    if(weight[n-1] <= w) {
        int op1 = knapsack(n-1, weight, val, w - weight[n-1]) + val[n-1];
        int op2 = knapsack(n-1, weight, val, w);
        return dp[n][w] = max(op1, op2);
    } else {
        int op2 = knapsack(n-1, weight, val, w);
        return dp[n][w] = op2;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, w;
        cin >> n >> w;
        int val[n], weight[n];
        for(int i = 0; i < n; i++) {
            cin >> weight[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> val[i];
        }

        memset(dp, -1, sizeof(dp));
        cout << knapsack(n, weight, val, w) << endl;
    }
    return 0;
}