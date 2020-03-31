//
//  main.cpp
//  538 - Convert BST to Greater Tree
//
//  Created by Wu, Meng Ju on 2020/3/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    void _traverse(TreeNode* root, int* total) {
        if (root != NULL) {
            _traverse(root->right, total);
            (*total) += root->val;
            root->val = (*total);
            _traverse(root->left, total);
        }
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        int total = 0;
        _traverse(root, &total);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
