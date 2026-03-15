#include <bits/stdc++.h>
using namespace std;

class Node{
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
    cout << endl;
}

void deleteHead(Node *&head) {
    if(head == NULL) {
        cout << "List is already empty."<< endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteTail(Node *&head) {
    if(head == NULL) {
        cout << "List is already empty." << endl;
        return;
    }
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

int getSize(Node *head) {
    Node *temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deletePos(Node *&head, int pos) {
    if(head == NULL) {
        cout << "List is already empty." << endl;
        return;
    }
    int size = getSize(head);
    if(pos < 0 || pos >= size) {
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    for(int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;

}

int main() {
    Node *head = NULL;
    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);
    printList(head);
    // deleteHead(head);
    // printList(head);
    // deleteTail(head);
    // printList(head);
    deletePos(head, 3);
    printList(head);
    return 0;
}