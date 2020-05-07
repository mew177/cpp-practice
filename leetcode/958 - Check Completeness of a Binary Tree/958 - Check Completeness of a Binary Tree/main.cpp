//
//  main.cpp
//  958 - Check Completeness of a Binary Tree
//
//  Created by Wu, Meng Ju on 2020/5/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // pair<Node, index>
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int prev = -1;
        
        while (!q.empty()) {
            auto [node, index] = q.front();
            q.pop();
            if (node) {
                if (index == prev + 1) {
                    prev = index;
                    q.push({node->left, index*2 + 1});
                    q.push({node->right, index*2 + 2});
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
