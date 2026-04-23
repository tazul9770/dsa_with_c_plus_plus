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

void insertHead(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertTail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

int size(Node *head) {
    Node *temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtPos(Node *head, int pos, int n) {
    Node *newNode = new Node(n);
    Node *temp = head;
    for(int i = 1; i <= pos-1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
}

void printList(Node *head) {
    Node *temp = head;
    cout << "L -> ";
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printReverse(Node *tail) {
    Node *temp = tail;
    cout << "R -> ";
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {

    Node *head = NULL;
    Node *tail = NULL;
    int q;
    cin >> q;
    while(q--) {
        int pos, val;
        cin >> pos >> val;
        if(pos < 0 || pos > size(head)) {
            cout << "Invalid" << endl;
            continue;
        } else if(pos == 0) {
            insertHead(head, tail, val);
        } else if(pos == size(head)) {
            insertTail(head, tail, val);
        } else {
            insertAtPos(head, pos, val);
        }
        printList(head);
        printReverse(tail);
    }
    return 0;
}