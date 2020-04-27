//
//  main.cpp
//  988 - Smallest String Starting From Leaf
//
//  Created by Wu, Meng Ju on 2020/4/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
    
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    string smallestStr = "~";
    void dfs(TreeNode* root, string str) {
        if (root) {
            str = char(root->val + 97) + str;
            if (!root->left && !root->right) {
                // if this is leaf node
                if (str < smallestStr) {
                    smallestStr = str;
                    return;
                }
            }
            
            dfs(root->left, str);
            dfs(root->right, str);
        }
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallestStr;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
