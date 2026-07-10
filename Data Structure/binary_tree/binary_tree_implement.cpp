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

void pre_order(Node *root) {
    if(root == NULL) {
        return;
    }
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(Node *root) {
    if(root == NULL) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}

void in_order(Node *root) {
    if(root == NULL) {
        return;
    }
    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
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

int main() {
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    d->left = f;
    e->left = g;
    e->right = h;

    cout << "Pre order print:" << endl;
    pre_order(root);
    cout << endl;
    cout << "Post order print:" << endl;
    post_order(root);
    cout << endl;
    cout << "In order print:" << endl;
    in_order(root);
    cout << endl;
    cout << "Level order print:" << endl;
    level_order(root);
    return 0;
}