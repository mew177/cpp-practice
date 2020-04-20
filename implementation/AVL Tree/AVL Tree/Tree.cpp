//
//  Tree.cpp
//  AVL Tree
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    int bf;
    int h;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

class BST {
private:
    int _inorder(TreeNode* root, int depth) {
        int ldep = depth, rdep = depth;
        if (root != NULL) {
            ldep = _inorder(root->left, depth+1);
            cout << root->val << " ";
            rdep = _inorder(root->right, depth+1);
        }
        depth = max(ldep, rdep);
        return depth;
    }
    
    void _insert(TreeNode* root, int val) {
        
        if (root->val >= val) {
            if (root->left == NULL) { root->left = new TreeNode(val); }
            else { _insert(root->left, val); }
        } else {
            if (root->right == NULL) { root->right = new TreeNode(val); }
            else { _insert(root->right, val); }
        }
    }
    
public:
    TreeNode* root;
    
    BST() {}
    ~BST() {}
    
    void inorder() {
        int depth = -1;
        if (root != NULL) {
            depth = _inorder(root, depth);
            cout << endl;
        }
        cout << "Tree Depth: " << depth << endl;
    }
    
    void insert(int val) {
        if (root != NULL) {
            _insert(root, val);
        } else {
            root = new TreeNode(val);
        }
    }
};

