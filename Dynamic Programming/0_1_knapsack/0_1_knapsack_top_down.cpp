#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
const int maxW = 1000;

int dp[maxN][maxW];

int knapsack(int n, int weight[], int val[], int W) {
    if(n == 0 || W == 0) {
        return 0;
    }
    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    if(weight[n-1] <= W) {
        int op1 = knapsack(n-1, weight, val, W-weight[n-1]) + val[n-1];
        int op2 = knapsack(n-1, weight, val, W);
        return dp[n][W] = max(op1, op2);
    } else {
        int op2 = knapsack(n-1, weight, val, W);
        return dp[n][W] = op2;
    }
}

int main() {
    int n;
    cin >> n;
    int weight[n], val[n];
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    int W;
    cin >> W;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            dp[i][j] == -1;
        }
    }

    cout << knapsack(n, weight, val, W);
    return 0;
}