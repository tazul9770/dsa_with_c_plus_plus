#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        string mostWord;
        map<string, int> m;
        int count = 0;
        while(ss >> word) {
            m[word]++;
            if(m[word] > count) {
                count = m[word];
                mostWord = word;
            }
        }
        cout << mostWord << " " << count << endl;
    }
    return 0;
}