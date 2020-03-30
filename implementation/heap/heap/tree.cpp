//
//  tree.cpp
//  heap
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include "tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

Tree::Tree() {
    root = NULL;
    size = 0;
};


Tree::~Tree() {
    destroy();
};

vector<TreeNode*> Tree::_heapify(TreeNode* root) {
    queue<TreeNode*> queue;
    vector<TreeNode*> array;
    queue.push(root);
    
    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        if (node != NULL) {
            array.push_back(node);
            queue.push(node->left);
            queue.push(node->right);
        }
    }
    return array;
}

vector<TreeNode*> Tree::heapify() {
    return _heapify(root);
}

void Tree::destroy() {
    _destroy(root);
};

void Tree::_destroy(TreeNode* root) {
    if (root != NULL) {
        _destroy(root->left);
        _destroy(root->right);
        delete root;
    }
};

void Tree::insert(int val) {
    if (root != NULL) {
        _insert(root, val);
    } else {
        root = new TreeNode(val);
    }
};

void Tree::_insert(TreeNode* root, int val) {
    if (root->val > val) {
        // should be store in left subtree
        if (root->left == NULL) {
            root->left = new TreeNode(val);
        } else { _insert(root->left, val); }
    } else if (root->val < val) {
        // should be store in right subtree
        if (root->right == NULL) {
            root->right = new TreeNode(val);
        } else { _insert(root->right, val); }
    } else  {
        // duplicate value
    }
};

void Tree::remove(int) {
    
};

bool Tree::_find(TreeNode* root, int val) {
    if (root == NULL) {
        return false;
    } else {
        if (val > root->val) {
            return _find(root->right, val);
        } else if (val < root->val) {
            return _find(root->left, val);
        } else {
            return true;
        }
    }
};

bool Tree::find(int val) {
    return _find(root, val);
};

void Tree::postorder() {
    _postorder(root);
    cout << endl;
};

void Tree::_postorder(TreeNode* root) {
    if (root != NULL) {
        _postorder(root->right);
        _postorder(root->left);
        cout << root->val << '\t';
    }
};

void Tree::inorder() {
    _inorder(root);
    cout << endl;
}

void Tree::_inorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->val << '\t';
        _inorder(root->left);
        _inorder(root->right);
    }
};

void Tree::_preorder(TreeNode* root) {
    if (root != NULL) {
        _preorder(root->left);
        std::cout << root->val << '\t';
        _preorder(root->right);
    }
};

void Tree::preorder() {
    _preorder(root);
    cout << endl;
};


