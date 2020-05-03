//
//  main.cpp
//  1038 - Binary Search Tree to Greater Sum Tree
//
//  Created by Wu, Meng Ju on 2020/4/25.
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
    void traverse(TreeNode* node, int* sum) {
        if (!node) return;
        traverse(node->right, sum);
        *sum += node->val;
        node->val = *sum;
        traverse(node->left, sum);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        // right -> center -> left
        int sum = 0;
        traverse(root, &sum);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
