#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    long long int ara[n];
    cout << "Enter array values: ";
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    long long int pref[n];
    pref[0] = ara[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + ara[i];
    }
    for(int i = n-1; i >= 0; i--) {
        cout << pref[i] << " ";
    }
    return 0;
}