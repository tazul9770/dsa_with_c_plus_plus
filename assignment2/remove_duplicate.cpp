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

void removeDup(Node *head) {
    if(head == NULL) {
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        Node *newNode = temp;
        while(newNode->next != NULL) {
            if(temp->value == newNode->next->value) {
                Node *deleteNode = newNode->next;
                newNode->next = newNode->next->next;
                delete deleteNode;
            } else {
                newNode = newNode->next;
            }
        }
        temp = temp->next;
    }
}

void insertTail(Node *&head, Node *&tail, int n) {
    Node *newNode = new Node(n);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
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
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    while(true) {
        cin >> n;
        if(n == -1) {
            break;
        }
        insertTail(head,tail, n);
    }
    removeDup(head);
    printList(head);
    return 0;
}