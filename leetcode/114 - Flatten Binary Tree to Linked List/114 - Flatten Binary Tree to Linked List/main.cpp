//
//  main.cpp
//  114 - Flatten Binary Tree to Linked List
//
//  Created by Wu, Meng Ju on 2020/3/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        TreeNode* node = root;
        TreeNode* rightMost;
        
        while (node) {
            if (node->left) {
                rightMost = node->left;
                while (rightMost->right) {
                    rightMost = rightMost->right;
                }

                rightMost->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
