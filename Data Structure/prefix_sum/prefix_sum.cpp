#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int ara[n];
    int pref[n];
    cout << "Enter your array: ";
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    pref[0] = ara[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + ara[i];
    }
    int l, r;
    cout << "Enter index of array: ";
    cin >> l >> r;
    if(l < 0 || r >= n || l > r) {
        cout << "Invalid index range!" << endl;
        return 0;
    }
    int sum;
    if(l == 0) {
        sum = pref[r];
    } else {
        sum = pref[r] - pref[l-1];
    }
    cout << "Final results: " << sum << endl;
    return 0;
}