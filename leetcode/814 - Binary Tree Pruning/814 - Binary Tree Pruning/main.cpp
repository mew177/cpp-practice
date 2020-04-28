//
//  main.cpp
//  814 - Binary Tree Pruning
//
//  Created by Wu, Meng Ju on 2020/4/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
    
    TreeNode* dfs(TreeNode* root) {
        if (root) {
            root->left = dfs(root->left);
            root->right = dfs(root->right);
            if (root->val == 0 && !root->left && !root->right)
                // leaf node with value 0 should be pruned
                root = NULL;
        }
        return root;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        root = dfs(root);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
