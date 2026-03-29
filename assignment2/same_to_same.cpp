#include <bits/stdc++.h>
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

void insertTail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

bool sameValue(Node *head1, Node *head2) {
    Node *x = head1;
    Node *y = head2;
    while(x != NULL && y != NULL) {
        if(x->val != y->val) {
            return false;
        }
        x = x->next;
        y = y->next;
    }
    return x == NULL && y == NULL;
}

int main() {
    Node *head1 = NULL;
    Node *tail1 = NULL;
    while(true) {
        int n;
        cin >> n;
        if(n == -1) {
            break;
        }
        insertTail(head1, tail1, n);
    }

    Node *head2 = NULL;
    Node *tail2 = NULL;
    while(true) {
        int m;
        cin >> m;
        if(m == -1) {
            break;
        }
        insertTail(head2, tail2, m);
    }
    if(sameValue(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}