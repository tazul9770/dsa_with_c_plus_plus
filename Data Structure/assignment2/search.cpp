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
void insertAtTail(Node *&head, Node *&tail, int n) {
    Node *newNode = new Node(n);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
int main() {
    
    int test;
    cin >> test;
    while(test--) {
        Node *head = NULL;
        Node *tail = NULL;
        int n;
        while(true) {
            cin >> n;
            if(n == -1) {
                break;
            }
            insertAtTail(head, tail, n);
        }
        int num;
        cin >> num;
        Node *temp = head;
        int found = 0;
        int indx = 0;
        while(temp != NULL) {
            indx++;
            if(temp->value == num) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if(found == 1) {
            cout << indx-1 << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    
    return 0;
}

