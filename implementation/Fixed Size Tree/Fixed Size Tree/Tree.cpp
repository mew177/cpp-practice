//
//  Tree.cpp
//  Fixed Size Tree
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Tree {
private:
    TreeNode* root;
    int treeSize;
    
    TreeNode* _buildTree(int idx) {
        if (idx < treeSize) {
            TreeNode* root = new TreeNode(idx);
            root->left = _buildTree(idx*2+1);
            root->right = _buildTree(idx*2+2);
            return root;
        } else {
            return NULL;
        }
    }
    
    
    void buildTree() {
        int idx = 0;
        root = new TreeNode(idx);
        root->left = _buildTree(idx*2+1);
        root->right = _buildTree(idx*2+2);
    }

    void _traverse(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node != NULL) {
                node->info();
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
    
    void _destroy(TreeNode* root) {
        if (root != NULL) {
            _destroy(root->left);
            _destroy(root->right);
            delete root;
        }
    }
    
public:
    Tree(): root(NULL), treeSize(0) {
        cout << "tree constructed" << endl;
    }
    
    Tree(int s): Tree(){
        treeSize = s;
        buildTree();
    }
    ~Tree() {
        _destroy(root);
    }
    
    void traverse() {
        _traverse(root);
    }
    
    TreeNode* get() {
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node != NULL) {
                if (node->isOccupied()) {
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    return node;
                }
            }
        }
        return NULL;
    }
    
    bool check(int number) {
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node != NULL) {
                if (node->index != number) {
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    if (!node->isOccupied()) {
                        cout << "Number: " << number << " is available" << endl;
                        return true;
                    } else { break; }
                }
            }
        }
        cout << "Number: " << number << " is not available" << endl;
        return false;
    }
    
    void release(int number) {
        TreeNode* node;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node != NULL) {
                if (node->index != number) {
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    node->set("", "");
                    node->release();
                }
            }
        }
    }
    
};
