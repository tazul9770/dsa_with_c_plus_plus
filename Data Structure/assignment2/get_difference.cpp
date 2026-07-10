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
    Node *min = head;
    Node *max = head;
    
    for(Node *i = head->next; i != NULL; i = i->next) {
        if(max->value < i->value) {
            max = i;
        } else if(min->value > i->value){
            min = i;
        }
    }
    cout << max->value - min->value << endl;
    
    return 0;
}

