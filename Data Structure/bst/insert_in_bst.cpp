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

void insert(Node *&root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return;
    }
    if(val < root->val) {
        if(root->left == NULL) {
            root->left = new Node(val);
        } else {
            insert(root->left, val);
        }
    } else {
        if(root->right == NULL) {
            root->right = new Node(val);
        } else {
            insert(root->right, val);
        }
    }
}

void level_order(Node *root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if(curr->left) {
            q.push(curr->left);
        }
        if(curr->right) {
            q.push(curr->right);
        }
    }
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
    insert(root, x);
    level_order(root);
    return 0;
}
