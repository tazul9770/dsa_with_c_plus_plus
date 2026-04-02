#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

int getSize(Node *head) {
    Node *temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAnyPos(Node *&head, int pos, int val) {
    int size = getSize(head);
    if(pos < 0 || pos > size) {
        cout << "Invalid position" << endl;
        return;
    }
    Node *newNode = new Node(val);
    if(pos == 0) {
        newNode->next = head;
        if(head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    Node *temp = head;
    for(int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

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

void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void printReverse(Node *tail) {
    Node *temp = tail;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    // insertAnyPos(head, 0, 10);
    // insertAnyPos(head, 0, 5);
    // insertAnyPos(head, 0, 20);

    // insertTail(head, tail, 10);
    // insertTail(head, tail, 20);
    // insertTail(head, tail, 30);
    // insertTail(head, tail, 40);

    insertHead(head, tail, 10);
    insertHead(head, tail, 20);
    insertHead(head, tail, 30);
    insertHead(head, tail, 40);

    printList(head);
    cout << endl;
    printReverse(tail);
    return 0;
}