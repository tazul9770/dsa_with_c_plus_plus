#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> mp;
    mp.insert({"tazul", 100});
    mp.insert({"sopna", 200});
    mp.insert({"sumi", 300});
    mp.insert({"Rana", 700});

    // for(auto it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->first << it->second << endl;
    // }

    cout << mp["tazul"] << endl;
    cout << mp["sorna"] << endl;
    
    if(mp.count("mojid")) {
        cout << "Mojid" << endl;
    } else {
        cout << "Nai" << endl;
    }
    return 0;
}