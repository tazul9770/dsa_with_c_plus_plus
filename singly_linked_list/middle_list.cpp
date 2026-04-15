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

int getSize(Node *head) {
    int count = 0;
    Node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *middle_node(Node *head) {
    int size = getSize(head);
    Node *temp = head;
    for(int i = 0; i < size/2; i++) {
        temp = temp->next;
    }
    return temp;
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

    Node *ans = middle_node(head);
    cout << ans->val << endl;
    
    return 0;
}