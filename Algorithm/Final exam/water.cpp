#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long int> v(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        auto mx = max_element(v.begin(), v.end());
        long long int max1 = *mx;
        auto it = find(v.begin(), v.end(), max1);
        long long int indx1 = distance(v.begin(), it);
        
        long long int max2 = INT_MIN;
        
        for(int num : v) {
            if(num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2 && num < max1) {
                max2 = num; 
            }
        }
        
        auto it2 = find(v.begin(), v.end(), max2);
        long long int indx2 = distance(v.begin(), it2);
        
        if(indx1 < indx2) {
            cout << indx1 << " " << indx2 << endl;
        } else {
            cout << indx2 << " " << indx1 << endl;
        }
    }
    
    return 0;
}
