#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *left;
    Node *right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void print_level(Node *root, int x) {
    queue<Node*> q;
    if(root != NULL) {
        q.push(root);
    }
    int l = 0;
    while(!q.empty()) {
        int size = q.size();
        if(l == x) {
            for(int i = 1; i <= size; i++) {
                Node *p = q.front();
                q.pop();
                cout << p->val << " ";
            }
            return;
        }
        for(int i = 1; i <= size; i++) {
            Node *n = q.front();
            q.pop();
            if(n->left) {
                q.push(n->left);
            }
            if(n->right) {
                q.push(n->right);
            }
        }
        l++;
    }
    cout << "Invalid" << endl;
}

Node *input_tree() {
    int val;
    cin >> val;
    Node *root;
    if(val == -1) {
        root = NULL;
    } else {
        root = new Node(val);
    }
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()) {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if(l == -1) {
            myLeft = NULL;
        } else {
            myLeft = new Node(l);
        }
        if(r == -1) {
            myRight = NULL;
        } else {
            myRight = new Node(r);
        }
        p->left = myLeft;
        p->right = myRight;
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}
int main() {
    Node *root = input_tree();
    int x;
    cin >> x;
    print_level(root, x);
    return 0;
}