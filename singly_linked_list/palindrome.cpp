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

void insertTail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool is_palindrome(Node *head) {
    Node *newHead = NULL;
    Node *newTail = NULL;
    Node *temp = head;
    while(temp != NULL) {
        insertTail(newHead, newTail, temp->val);
        temp = temp->next;
    }
    Node *reverseNewHead = reverse(newHead);
    temp = head;
    Node *temp2 = reverseNewHead;

    while(temp != NULL) {
        if(temp->val != temp2->val) {
            return false;
        }
        temp = temp->next;
        temp2 = temp2->next;
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

    if(is_palindrome(head)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not palindrome" << endl;
    }
    
    return 0;
}