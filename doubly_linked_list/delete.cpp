#include <bits/stdc++.h>
using namespace std;

class Node{
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

int getSize(Node *head) {
    Node *temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteAnyPos(Node *&head, Node *&tail, int pos) {
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
        head = temp->next;
        if(head != NULL) head->prev = NULL;
        else tail = NULL; 
        delete temp;
        return;
    }

    if(pos == size - 1) {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return;
    }

    Node *temp = head;
    for(int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}


void deleteHead(Node *&head, Node *&tail) {
    if(head == NULL) {
        cout << "List is already empty.";
        return;
    }
    Node *temp = head;
    if(head->next == NULL) {
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deleteTail(Node *&head, Node *&tail) {
    if(head == NULL) {
        cout << "List is already empty." << endl;
        return;
    }
    if(head->next == NULL) {
        head = NULL;
        tail = NULL;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}


int main() {
    Node *head = NULL;
    Node *tail = NULL;

    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    insertTail(head, tail, 30);
    insertTail(head, tail, 40);

    //deleteAnyPos(head, tail, 3);
    //deleteHead(head, tail);
    deleteTail(head, tail);

    printList(head);
    cout << endl;
    printReverse(tail);

    return 0;
}