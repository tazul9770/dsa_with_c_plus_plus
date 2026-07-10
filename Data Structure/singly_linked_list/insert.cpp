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

void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void insertHead(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertTail(Node *&head, int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int getSize(Node *head) {
    int count = 0;
    Node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAnyPosition(Node *&head, int pos, int val) {
    int size = getSize(head);
    if(pos < 0 || pos > size) {
        cout << "Invalid position.";
        return;
    }
    Node *newNode = new Node(val);
    if(pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *temp = head;
    for(int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node *head = NULL;
    // insertTail(head, 10);
    // insertTail(head, 20);
    // printList(head);
    // insertHead(head, 10);
    // insertHead(head, 20);
    // insertHead(head, 30);
    // printList(head);
    insertAnyPosition(head, 0, 10);
    insertAnyPosition(head, 1, 90);
    printList(head);
    return 0;
}