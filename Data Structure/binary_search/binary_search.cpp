#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int ara[n];  
    cout << "Enter array values: ";
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }

    sort(ara, ara + n);   

    int x;
    cout << "Enter number: ";
    cin >> x;

    int low = 0, high = n - 1;
    bool flag = false;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(ara[mid] == x) {
            flag = true;
            cout << "Number found: " << ara[mid];
            break;
        }
        else if(ara[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(!flag) {
        cout << "Number not found.";
    }

    return 0;
}