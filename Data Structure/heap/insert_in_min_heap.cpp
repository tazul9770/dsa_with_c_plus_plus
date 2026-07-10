#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        int curr_indx = v.size()-1;
        while(curr_indx != 0) {
            int parent_indx = (curr_indx-1)/2;
            if(v[parent_indx] > v[curr_indx]) {
                swap(v[parent_indx], v[curr_indx]);
                curr_indx = parent_indx;
            } else {
                break;
            }
        }
    }
    for(int val : v) {
        cout << val << " ";
    }
    return 0;
}