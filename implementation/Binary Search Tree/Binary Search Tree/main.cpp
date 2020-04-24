//
//  main.cpp
//  Binary Search Tree
//
//  Created by Wu, Meng Ju on 2020/4/24.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

// this BST avoid storing identical value
struct BST {
    TreeNode* root;
    BST(): root(NULL) {}
    
    /* insertion */
    TreeNode* _insert(TreeNode* root, int val) {
        if (root == NULL) { return new TreeNode(val); }
        if (root) {
            if (root->val > val) {
                // to left subtree
                root->left = _insert(root->left, val);
            } else if (root->val < val) {
                root->right = _insert(root->right, val);
            }
        }
        return root;
    }
    
    void insert(int val) {
        if (!root)
            root = new TreeNode(val);   // if root is not defined yet
        else
            _insert(root, val);
    }
    
    /* find */
    TreeNode* find(int val) {
        if (root)
            return _find(root, val);
        else
            return NULL;
    }
    
    TreeNode* _find(TreeNode* root, int val) {
        if (!root) { return NULL; } // reach leaf node
        if (root->val > val)
            // in left subtree
            return _find(root->left, val);
        else if (root->val < val)
            // in right subtree
            return _find(root->right, val);
        else
            // found
            return root;
    }
    
    /* remove */
    void remove(int val) {
        if (root)
            root = _remove(root, val);
    }
    
    TreeNode* _remove(TreeNode* root, int val) {
        if (!root) { return NULL; } // not found
        if (root->val > val) {
            // in left subtree
            root->left = _remove(root->left, val);
        } else if (root->val < val) {
            // in right subtree
            root->right = _remove(root->right, val);
        } else {
            // found
            if (!root->left and !root->right) {
                // if target node doesn't have any child
                // case 1
                return NULL;
            } else if (!root->left) {
                // target node only has right child
                // case 2
                return root->right;
            } else if (!root->right) {
                // target node only has left child
                // case 3
                return root->left;
            } else {
                // target node has both right ans left child
                // case 4
                TreeNode* rightSmallest = root->right;
                // find the smallest node on right subtree
                while (rightSmallest->left)
                    rightSmallest = rightSmallest->left;
                // replace the value of target value with right smallest value
                root->val = rightSmallest->val;
                // this time we have two smallest value in this tree
                // remove rightSmallest value from right subtree
                root->right = _remove(root->right, rightSmallest->val);
            }
        }
        return root;
    }
    
    
    /* print */
    void print() {
        _print(root);
    }
    
    void _print(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* next = q.front();
            q.pop();
            if (next) {
                cout << next->val << " ";
                q.push(next->left);
                q.push(next->right);
            }
        }
        cout << '\n';
    }
};

int main(int argc, const char * argv[]) {
    
    BST tree;
    vector<int> nums = {4, 3, 8, 2, 5, 10, 1, 6, 7, 9, 11};
    for (int num : nums)
        tree.insert(num);
    tree.print(); // should print [4, 3, 8, 2, 5, 10, 1, 6, 9, 11, 7]
    
    cout << tree.find(7) << endl;       // shouldn't found, return 0x0
    cout << tree.find(6)->val << endl;  // should found, return 6
    cout << tree.find(4)->val << endl;  // should found, return 4
    
    tree.remove(1); // case 1
    tree.print();   // should print [4, 3, 8, 2, 5, 10, 6, 9, 11, 7]
    tree.remove(3); // case 2
    tree.print();   // should print [4, 2, 8, 5, 10, 6, 9, 11, 7]
    tree.remove(5); // case 3
    tree.print();   // should print [4, 2, 8, 6, 10, 7, 9, 11]
    tree.remove(8); // case 4
    tree.print();   // should print [4, 2, 9, 6, 10, 7, 11]
    tree.remove(4); // remove root node
    tree.print();   // should print [6, 2, 9, 7, 10, 11]
    
    return 0;
}
