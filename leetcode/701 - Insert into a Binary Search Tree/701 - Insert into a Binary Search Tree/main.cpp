//
//  main.cpp
//  701 - Insert into a Binary Search Tree
//
//  Created by Wu, Meng Ju on 2020/4/24.
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
    TreeNode* _insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val < val) {
            root->right = _insert(root->right, val);
        } else {
            root->left = _insert(root->left, val);
        }
        return root;
    }
    
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root)
            root = _insert(root, val);
        else
            root = new TreeNode(val);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
