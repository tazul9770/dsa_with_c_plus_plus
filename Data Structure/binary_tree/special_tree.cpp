//left and right 2 tai thakle tobe thake special tree dhorbe
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

bool special_tree(Node *root) {
    if(root->left == NULL && root->right == NULL) return true;
    if(root->left == NULL || root->right == NULL) return false;
    bool l = special_tree(root->left);
    bool r = special_tree(root->right);
    if(l == false || r == false) return false;
    return true;
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
    if(special_tree(root)) {
        cout << "Special tree" << endl;
    } else {
        cout << "Not special tree" << endl;
    }
    return 0;
}