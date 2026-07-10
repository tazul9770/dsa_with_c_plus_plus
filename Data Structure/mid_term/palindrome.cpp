#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *prev;
    Node *next;
    Node(int val) {
        this->val = val;
        this->prev = NULL;
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
    newNode->prev = tail;
    tail = newNode;
}

bool is_palindrome(Node *head, Node *tail) {
    Node *temp1 = head;
    Node *temp2 = tail;
    while(temp1 != NULL) {
        if(temp1->val != temp2->val) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    return true;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    while(true) {
        int n;
        cin >> n;
        if(n == -1) {
            break;
        }
        insertTail(head, tail, n);
    }

    if(is_palindrome(head, tail)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}