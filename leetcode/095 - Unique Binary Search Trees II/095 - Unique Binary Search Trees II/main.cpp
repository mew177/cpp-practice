//
//  main.cpp
//  095 - Unique Binary Search Trees II
//
//  Created by Wu, Meng Ju on 2020/4/27.
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
    
    vector<TreeNode*> buildTree(int start, int end) {
        if (start > end) { return vector<TreeNode*>(1, NULL); }
        
        vector<TreeNode*> all_trees;
        // pick a number as root node
        for (int center = start; center <= end; center++) {
            // build left tree from left section
            vector<TreeNode*> left_trees = buildTree(start, center-1);
            // build right tree from right section
            vector<TreeNode*> right_trees = buildTree(center+1, end);
            
            for (TreeNode* left : left_trees) {
                for (TreeNode* right : right_trees) {
                    TreeNode* root = new TreeNode(center);
                    root->left = left;
                    root->right = right;
                    all_trees.push_back(root);
                }
            }
        }
        return all_trees;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : buildTree(1, n);
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
