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

void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void reverse(Node *head) {
    if(head == NULL) {
        return;
    }
    reverse(head->next);
    cout << head->val << " ";
}

int main() {
    Node *head = NULL;
    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);
    reverse(head);
    printList(head);
    return 0;
}