//
//  main.cpp
//  1382 - Balance a Binary Search Tree
//
//  Created by Wu, Meng Ju on 2020/4/25.
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
    
    void dfs(TreeNode* node, vector<TreeNode*>& path) {
        if (node) {
            dfs(node->left, path);
            path.push_back(node);
            dfs(node->right, path);
        }
    }
    
    TreeNode* inorder(vector<TreeNode*>& path, int l, int r) {
        if (l > r) { return NULL; }
        int m = (l + r) / 2 ;
        TreeNode* root = path[m];
        root->left = inorder(path, l, m-1);
        root->right = inorder(path, m+1, r);
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> path;
        dfs(root, path);
        return inorder(path, 0, path.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
