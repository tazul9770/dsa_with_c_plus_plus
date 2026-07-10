#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    string val;
    Node *prev;
    Node *next;
    Node(string val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertTail(Node *&head, Node *&tail, string val) {
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

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    while(true) {
        string addr;
        cin >> addr;
        if(addr == "end") {
            break;
        }
        insertTail(head, tail, addr);
    }
    Node *curr = head;
    int q;
    cin >> q;
    while(q--) {
        string command, url;
        cin >> command;
        if(command == "visit") {
            cin >> url;
            Node *temp = head;
            bool flag = false;
            while(temp != NULL) {
                if(temp->val == url) {
                    curr = temp;
                    flag = true;
                    cout << curr->val << endl;
                    break;
                }
                temp = temp->next;
            }
            if(flag == false) {
                cout << "Not Available" << endl;
            }
        } else if(command == "next") {
            if(curr->next == NULL) {
                cout << "Not Available" << endl;
            } else {
                curr = curr->next;
                cout << curr->val << endl;
            }
        } else if(command == "prev") {
            if(curr->prev == NULL) {
                cout << "Not Available" << endl;
            } else {
                curr = curr->prev;
                cout << curr->val << endl;
            }
        }
    }
    return 0;
}