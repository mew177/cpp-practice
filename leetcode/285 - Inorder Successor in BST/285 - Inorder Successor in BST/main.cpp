//
//  main.cpp
//  285 - Inorder Successor in BST
//
//  Created by Wu, Meng Ju on 2020/3/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
    void _inorder(TreeNode* root, vector<TreeNode*> path) {
        if (root != NULL) {
            _inorder(root->left, path);
            path.push_back(root);
            _inorder(root->right, path);
        }
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> path;
        _inorder(root, path);
        
        for (int i = 0 ; i < path.size()-1; i++) {
            if (path[i] == p) {
                return path[i+1];
            }
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
