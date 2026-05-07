// Maximum equal stack sum (Coding Ninja)
#include <bits/stdc++.h>
using namespace std;

int getSum(stack<int> s) {
    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    return sum;
}

int maxSum(stack<int> &s1, stack<int> &s2, stack<int> &s3) {
    int sum1 = getSum(s1);
    int sum2 = getSum(s2);
    int sum3 = getSum(s3);
    while(true) {
        if(sum1 == sum2 && sum2 == sum3) {
            break;
        }
        if(sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= s1.top();
            s1.pop();
        } else if(sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= s2.top();
            s2.pop();
        } else {
            sum3 -= s3.top();
            s3.pop();
        }
    }
    return sum1;
}

int main() {
    stack<int> s1;
    while(true) {
        int x;
        cin >> x;
        if(x == -1) {
            break;
        }
        s1.push(x);
    }
    stack<int> s2;
    while(true) {
        int x;
        cin >> x;
        if(x == -1) {
            break;
        }
        s2.push(x);
    }
    stack<int> s3;
    while(true) {
        int x;
        cin >> x;
        if(x == -1) {
            break;
        }
        s3.push(x);
    }

    cout << "Maximum equal stack sum: " << maxSum(s1, s2, s3);
    return 0;
}