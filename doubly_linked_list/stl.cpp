#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int> myList = {10, 20, 10, 30, 15, 25, 18, 40};
    // myList.push_back(40);
    // myList.push_back(50);
    // myList.push_front(100);
    // myList.pop_back();
    //myList.remove(10);
    //myList.sort();
    //myList.sort(greater<>());
    //myList.unique();
    //myList.reverse();
    cout << myList.front() << " " << myList.back() << endl;
    //cout << *next(myList.begin(), 4) << endl; // myList loop
    for(int val : myList){
        cout << val << " ";
    }
    return 0;
}