#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int ara[n];
    cout << "Enter array value: ";
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    
    bool flag = false;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(ara[i] == ara[j]) {
                flag = true;
                break;
            }
        }
    }
    
    if(!flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
