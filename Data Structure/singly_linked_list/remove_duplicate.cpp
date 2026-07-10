//only sorted list need for remove duplicate
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

Node *remove_duplicate(Node *head) {
    Node *temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val) {
            Node* duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        } else {
            temp = temp->next;
        }
    }

    return head;
}

int main() {

    Node *head = NULL;
    while(true) {
        int n;
        cin >> n;
        if(n == -1) {
            break;
        }
        insertTail(head, n);
    }

    Node *result = remove_duplicate(head);
    printList(result);
    
    return 0;
}