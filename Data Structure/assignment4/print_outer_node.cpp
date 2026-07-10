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

void left_outer_node(Node *root) {
    if(root == NULL) {
        return;
    }
    if(root->left != NULL) {
        left_outer_node(root->left);
        cout << root->left->val << " ";
    } else if(root->right != NULL) {
        left_outer_node(root->right);
        cout << root->right->val << " ";
    }
}

void right_outer_node(Node *root) {
    if(root == NULL) {
        return;
    }
    if(root->right != NULL) {
        cout << root->right->val << " ";
        right_outer_node(root->right);
    } else if(root->left != NULL) {
        cout << root->left->val << " ";
        right_outer_node(root->left);
    }
}

void print_outer_node(Node *root) {
    if(root == NULL) {
        return;
    }
    if(root->left != NULL && root->right != NULL) {
        left_outer_node(root);
        cout << root->val << " ";
        right_outer_node(root);
    } else if(root->left == NULL) {
        cout << root->val << " ";
        right_outer_node(root);
    } else if(root->right == NULL) {
        left_outer_node(root);
        cout << root->val << " ";
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
    print_outer_node(root);
    return 0;
}