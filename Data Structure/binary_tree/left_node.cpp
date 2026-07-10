// binary tree er sob left node print korte hobe
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

vector<int> left_node(Node *root) {
    bool freq[105] = {false};
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    vector<int> v;
    while(!q.empty()) {
        auto parent = q.front();
        Node *node = parent.first;
        int level = parent.second;
        q.pop();
        if(freq[level] == false) {
            v.push_back(node->val);
            freq[level] = true;
        }
        if(node->left) {
            q.push({node->left, level+1});
        }
        if(node->right) {
            q.push({node->right, level+1});
        }
    }
    return v; 
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
    vector<int> ans = left_node(root);
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
