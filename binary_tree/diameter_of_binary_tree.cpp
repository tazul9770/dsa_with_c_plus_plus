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

int mx = 0;

int max_height(Node *root) {
    if(root == NULL) {
        return 0;
    }
    int l = max_height(root->left);
    int r = max_height(root->right);
    int d = l+r;
    mx = max(mx, d);
    return max(l, r) + 1;
}

int diameter_of_binary_tree(Node *root) {
    mx = 0;
    int h = max_height(root);
    return mx;
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
    int d = diameter_of_binary_tree(root);
    cout << "Diameter: " << d;
    return 0;
}