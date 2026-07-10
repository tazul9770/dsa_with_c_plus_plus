#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int x) {
    v.push_back(x);
        int curr_indx = v.size()-1;
        while(curr_indx != 0) {
            int parent_indx = (curr_indx-1)/2;
            if(v[parent_indx] < v[curr_indx]) {
                swap(v[parent_indx], v[curr_indx]);
                curr_indx = parent_indx;
            } else {
                break;
            }
        }
}

void print_heap(vector<int> v) {
    for(int val : v) {
        cout << val << " ";
    }
}

void delete_heap(vector<int> &v) {
    v[0] = v[v.size()-1];
    v.pop_back();
    int curr_indx = 0;
    while(true) {
        int left_indx = curr_indx*2+1;
        int right_indx = curr_indx*2+2;
        int last_indx = v.size()-1;
        if(left_indx <= last_indx && right_indx <= last_indx) {
            if(v[left_indx] >= v[right_indx] && v[left_indx] > v[curr_indx]) {
                swap(v[left_indx], v[curr_indx]);
                curr_indx = left_indx;
            } else if(v[right_indx] >= v[left_indx] && v[right_indx] > v[curr_indx]) {
                swap(v[right_indx], v[curr_indx]);
                curr_indx = right_indx;
            } else {
                break;
            }
        } else if(left_indx <= last_indx) {
            if(v[left_indx] > v[curr_indx]) {
                swap(v[left_indx], v[curr_indx]);
                curr_indx = left_indx;
            } else {
                break;
            }
        } else if(right_indx <= last_indx) {
            if(v[right_indx] > v[curr_indx]) {
                swap(v[right_indx], v[curr_indx]);
                curr_indx = right_indx;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert_heap(v, x);
    }
    delete_heap(v);
    delete_heap(v);
    print_heap(v);
    return 0;
}