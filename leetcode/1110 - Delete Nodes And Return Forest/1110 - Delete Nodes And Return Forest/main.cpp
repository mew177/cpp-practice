//
//  main.cpp
//  1110 - Delete Nodes And Return Forest
//
//  Created by Wu, Meng Ju on 2020/4/18.
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
    TreeNode* traverse(TreeNode* root, TreeNode* parent, vector<int>& to_delete, vector<TreeNode*>& ans) {
        if (root != NULL) {
            vector<int>::iterator it = find(to_delete.begin(), to_delete.end(), root->val);
            if (it == to_delete.end()) {
                // not in to_delete
                if (parent == NULL) {
                    ans.push_back(root);
                }
                root->left = traverse(root->left, root, to_delete, ans);
                root->right = traverse(root->right, root, to_delete, ans);
            } else {
                // in to_delete
                traverse(root->left, NULL, to_delete, ans);
                traverse(root->right, NULL, to_delete, ans);
                root = NULL;
            }
        }
        return root;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        traverse(root, NULL, to_delete, ans);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
