//
//  main.cpp
//  366 - Find Leaves of Binary Tree
//
//  Created by Wu, Meng Ju on 2020/4/25.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
    TreeNode* removeLeaves(TreeNode* root, vector<int>& path) {
        if (root) {
            if (!root->left && !root->right) {
                // if both left node and right node is NULL
                // this is a leaf node
                path.push_back(root->val);
                return NULL;
            } else {
                // if root has left child or right child
                // this is not a leaf node
                root->left = removeLeaves(root->left, path);
                root->right = removeLeaves(root->right, path);
            }
        }
        return root;
    }
    
    void iterative(TreeNode* root, vector<vector<int>>& leaves) {
        
        while (root) {
            vector<int> path;
            if (!root->left && !root->right) {
                // if root is a leaf node
                path.push_back(root->val);
                leaves.push_back(path);
                break;
            }
            
            queue<TreeNode*> q;
            q.push(root);
            
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    cout << node->val << endl;
                    if (node->left && !node->left->left && !node->left->right) {
                        // if left child is a leaf
                        // push as leaf node and set left child as NULL
                        //cout << node->left->val << " is leaf" << endl;
                        path.push_back(node->left->val);
                        node->left = NULL;
                    }

                    if (node->right && !node->right->left && !node->right->right) {
                        // if right child is a leaf
                        // push as leaf node and set right child as NULL
                        //cout << node->right->val << " is leaf" << endl;
                        path.push_back(node->right->val);
                        node->right = NULL;
                    }
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            leaves.push_back(path);
            
        }
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        iterative(root, leaves);
        return leaves;
        
        
        vector<int> path;
        while (root) {
            // if root is not NULL
            // there is more leaf nodes to be collected
            root = removeLeaves(root, path);
            leaves.push_back(path);
            path.clear();
        }
        return leaves;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
