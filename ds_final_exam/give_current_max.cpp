#include<bits/stdc++.h>
using namespace std;
class Student {
    public:
        string name;
        int roll;
        int marks;
    Student(string name, int roll, int marks) {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};
class cmp {
    public:
        bool operator()(Student a, Student b) {
            if(a.marks == b.marks) {
                if(a.roll > b.roll) {
                    return true;
                } else {
                    return false;
                }
            }
            if(a.marks < b.marks) {
                return true;
            } else {
                return false;
            }
        }
};
int main() {
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cmp> pq;
    for(int i = 0; i < n; i++) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }
    int q;
    cin >> q;
    while(q--) {
        int c;
        cin >> c;
        if(c == 0) {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            Student s = pq.top();
            cout << s.name << " " << s.roll << " " << s.marks << endl;
        } else if(c == 1) {
            if(pq.empty()) {
                cout << "Empty" << endl;
            } else {
                Student s = pq.top();
                cout << s.name << " " << s.roll << " " << s.marks << endl;
            }
        } else if(c == 2) {
            if(pq.empty()) {
                cout << "Empty" << endl;
            } else {
                pq.pop();
                if(pq.empty()) {
                    cout << "Empty" << endl;
                } else {
                    Student s = pq.top();
                    cout << s.name << " " << s.roll << " " << s.marks << endl;
                }
            }
        }
    }
    return 0;
}
