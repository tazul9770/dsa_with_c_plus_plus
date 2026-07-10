#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int value;
        Node *next;
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};
void deleteFromPos(Node *&head, int pos) {
    if (head == NULL) {
        return;
    }
    Node *temp = head;
    if (pos == 0) {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    Node *newNode = temp->next->next;
    delete temp->next;
    temp->next = newNode;
}
void insertAtTail(Node *&head, int n) {
    Node *newNode = new Node(n);
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
void insertHead(Node *&head, int n) {
    Node *newNode = new Node(n);
    newNode->next = head;
    head = newNode;
}
void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int q;
    cin >> q;
    Node *head = NULL;
    while(q--) {
        int pos, val;
        cin >> pos >> val;
        if(pos == 0) {
            insertHead(head, val);
        } else if(pos == 1) {
            insertAtTail(head, val);
        } else if(pos == 2) {
            deleteFromPos(head, val);
        }
        printList(head);
    }
    return 0;
}