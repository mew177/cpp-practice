//
//  main.cpp
//  226 - Invert Binary Tree
//
//  Created by Wu, Meng Ju on 2020/3/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    
public:
    TreeNode* invertTree(TreeNode *root) {
        if (root != NULL) {
            // invert left and right childe
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
