// Tree te node khuja? ache kina khuje ber korte hobe
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

bool is_node_present(Node *root, int x) {
    if(root == NULL) {
        return false;
    }
    if(root->val == x) {
        return true;
    }
    bool l = is_node_present(root->left, x);
    bool r = is_node_present(root->right, x);
    return l || r;
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
    q.push(root);
    while(!q.empty()) {
        Node *p = q.front();
        q.pop();
        Node *myLeft;
        Node *myRight;
        int l, r;
        cin >> l >> r;
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
        if(p->left) {
            q.push(p->left);
        }
        if(p->right) {
            q.push(p->right);
        }
    }
    return root;
}
int main() {
    Node *root = input_tree();
    int x;
    cin >> x;
    if(is_node_present(root, x)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}