//
//  main.cpp
//  AVL Search Tree
//
//  Created by Wu, Meng Ju on 2020/4/24.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    int height;
    int bf;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), bf(0), left(NULL), right(NULL) {}
};

struct AVL {
    TreeNode* root;
    AVL(): root(NULL) {}
    
    /* insertion */
    void insert(int val) {
        if (!root)
            root = new TreeNode(val);
        else
            root = _insert(root, val);
    }
    
    TreeNode* _insert(TreeNode* root, int val) {
        if (!root) { return new TreeNode(val); }
        if (root->val < val) {
            // in right subtree
            root->right = _insert(root->right, val);
        } else if (root->val > val) {
            // in left subtree
            root->left = _insert(root->left, val);
        }
        // update bf bottom up
        update(root);
        return balanced(root); // balanced the tree bottom up
    }
    
    /* update balance factor in tree */
    void update(TreeNode* root) {
        int lh = -1; // height from left subtree
        int rh = -1; // height from right subtree
        if (root->right) { rh = root->right->height; }
        if (root->left) { lh = root->left->height; }
        int height = max(rh, lh) + 1; // update height
        int bf = rh - lh;   // balance factor in calculated as rh - lh
        root->height = height;
        root->bf = bf;
    }
    
    /* balance this subtree */
    TreeNode* balanced(TreeNode* root) {
        if (root->bf == -2) {
            // left tilted
            if (root->left->bf <= 0) {
                // left node doesn't have right child
                // left left case
                root = LeftLeftCase(root);
            } else {
                // left right case
                root = LeftRightCase(root);
            }
        } else if (root->bf == 2) {
            // right tilted
            if (root->right->bf >= 0) {
                // right node doesn't have left child
                // right right case
                root = RightRightCase(root);
            } else {
                // right left case
                root = RightLeftCase(root);
            }
        }
        return root;
    }
    
    TreeNode* LeftLeftCase(TreeNode* node) {
        // right rotate one time
        return rightRotate(node);
    }
    
    TreeNode* RightRightCase(TreeNode* node) {
        // left rotate one time
        return leftRotate(node);
    }
    
    TreeNode* LeftRightCase(TreeNode* node) {
        // left rotate on left node one time
        // right rotate on node one time
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    TreeNode* RightLeftCase(TreeNode* node) {
        // right rotate on right node one time
        // left rotate on node one time
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    TreeNode* rightRotate(TreeNode* node) {
        TreeNode* B = node->left;
        node->left = B->right;
        B->right = node;
        update(node);
        update(B);
        return B;
    }
    
    TreeNode* leftRotate(TreeNode* node) {
        TreeNode* B = node->right;
        node->right = B->left;
        B->left = node;
        update(node);
        update(B);
        return B;
    }
    
    /* remove */
    void remove(int val) {
        if (root)
            root = _remove(root, val);
    }
    
    TreeNode* _remove(TreeNode* root, int val) {
        if (!root) { return NULL; } // Not found
        if (root->val < val) {
            // in right subtree
            root->right = _remove(root->right, val);
        } else if (root->val > val) {
            // in left subtree
            root->left = _remove(root->left, val);
        } else {
            // found
            if (!root->left && !root->right) {
                // node is leaf
                return NULL;
            } else if (!root->left) {
                // node has only right child
                return root->right;
            } else if (!root->right) {
                // node has only left child
                return root->left;
            } else {
                // node has both left and right child
                TreeNode* rightSmallest = root->right;
                while (rightSmallest->left)
                    rightSmallest = rightSmallest->left;
                root->val = rightSmallest->val;
                root->right = _remove(root->right, rightSmallest->val);
            }
        }
        update(root);
        return balanced(root);
    }
    
    /* find */
    
    TreeNode* find(int val) {
        if (root)
            return _find(root, val);
        else
            return NULL;
    }
    
    TreeNode* _find(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val < val)
            return _find(root->right, val);
        else if (root->val > val)
            return _find(root->left, val);
        else
            return root;
    }
    
    void print() {
        if (!root) { cout << '\n'; }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
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
    
    AVL tree;
    
    // test insertion
    tree.insert(5);
    tree.print();
    tree.insert(3);
    tree.print();
    tree.insert(2);
    tree.print();
    tree.insert(1);
    tree.print();
    tree.insert(6);
    tree.print();
    tree.insert(7);
    tree.print();
    tree.insert(9);
    tree.print();
    
    // test find
    cout << tree.find(5) << endl;
    cout << tree.find(12) << endl;
    cout << tree.find(3) << endl;
    
    // test removal
    tree.remove(9);
    tree.print();
    tree.remove(2);
    tree.print();
    tree.remove(1);
    tree.print();
    
    return 0;
}
