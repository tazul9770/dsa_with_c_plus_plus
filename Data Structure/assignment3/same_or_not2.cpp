#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class myStack {
    public:
    vector<int> v;
    void push(int val) {
        v.push_back(val);
    }
    void pop() {
        v.pop_back();
    }
    int top() {
        return v.back();
    }
    int size() {
        return v.size();
    }
    bool empty() {
        if(v.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};

class myQueue {
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val) {
        sz++;
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop() {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        if(head == NULL) {
            tail = NULL;
        }
    }

    int front() {
        return head->val;
    }

    int size() {
        return sz;
    }

    bool empty() {
        if(sz == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    myStack s;
    myQueue q;
    int n, m;
    cin >> n >> m;
    while(n--) {
        int val;
        cin >> val;
        s.push(val);
    }
    while(m--) {
        int val;
        cin >> val;
        q.push(val);
    }
    if(s.size() != q.size()) {
        cout << "NO" << endl;
    } else {
        bool flag = true;
        while(!s.empty()) {
            if(s.top() != q.front()) {
                flag = false;
                break;
            }
            s.pop();
            q.pop();
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}