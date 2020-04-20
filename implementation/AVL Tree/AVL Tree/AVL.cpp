//
//  AVL.cpp
//  AVL Tree
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include "AVL.hpp"
#include <algorithm>
#include <queue>
#include <iostream>

// constructor & deconstructor
AVL::AVL(): root(NULL) {
    
};

AVL::~AVL() {
    
};

// private functions
TreeNode* AVL::_insert(TreeNode* node, int value) {
    if (node == NULL) {
        return new TreeNode(value);
    }
    
    // compare value
    if (node->val > value)
        node->left = _insert(node->left, value);
    else
        node->right = _insert(node->right, value);
    
    // update node
    _update(node);
    
    // balance node
    return _balance(node);
};

void AVL::_update(TreeNode* node) {
    int lh = -1; // height of left subtree
    int rh = -1; // height of right subtree
    
    // get height from both subtree
    if (node->left != NULL) lh = node->left->h;
    if (node->right != NULL) rh = node->right->h;
    
    // update height
    node->h = (1 + std::max(lh, rh));
    // update balance factor
    node->bf = rh - lh;
};

TreeNode* AVL::_balance(TreeNode* node){
    /*
        AVL tree could accept balance factor to be [-1, 0, 1]
        In this case, node could at most have balance factor to be
        [-2, -1, 0, 1, 2], so we just deal with bf= -2, 2
     */
    
    // left subtree is heavier
    if (node->bf == -2) {
        if (node->left->bf <= 0){
            // left child doesn't have right child
            node = leftLeftCase(node);
        } else {
            // left child has right child
            node = leftRotate(node);
        }
    } else if (node->bf == 2) {
        if (node->right->bf >= 0) {
            // right child doesn't have left child
            node = rightRightCase(node);
        } else {
            // right child has left child
            node = rightLeftCase(node);
        }
    }
    
    return node;
};

TreeNode* AVL::rightRotate(TreeNode* node) {
    // left subtree is heavier than right subtree
    TreeNode* B = node->left;
    node->left = B->right;
    B->right = node;
    _update(node);
    _update(B);
    return B;
};

TreeNode* AVL::leftRotate(TreeNode* node) {
    // right subtree is heavier than left subtree
    TreeNode* C = node->right;
    node->right = C->left;
    C->left = node;
    _update(node);
    _update(C);
    return C;
};

TreeNode* AVL::leftLeftCase(TreeNode* node) {
    // do right rotate on node
    return rightRotate(node);
};

TreeNode* AVL::leftRightCase(TreeNode* node) {
    // first left rotate on node->left
    // right rotate on node
    node->left = leftRotate(node->left);
    return rightRotate(node);
};

TreeNode* AVL::rightRightCase(TreeNode* node) {
    // do left rotate on node
    return leftRotate(node);
};

TreeNode* AVL::rightLeftCase(TreeNode* node) {
    // first right rotate on node->right
    // left rotate on node
    node->right = rightRotate(node->right);
    return leftRotate(node);
};

// public functions
void AVL::insert(int value) {
    if (root == NULL) {
        root = new TreeNode(value);
    } else {
        root = _insert(root, value);
    }
};

void AVL::traverse() {
    if (root == NULL) { return; }
    
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* node;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (node != NULL) {
            std::cout << node->val << " ";
            if (node->left != NULL || node->right != NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        } else {
            std::cout << "NULL" << " ";
        }
    }
};

void AVL::print() {
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* node;
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (node != NULL) {
            std::cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    std::cout << std::endl;
}
