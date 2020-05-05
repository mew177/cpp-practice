//
//  main.cpp
//  102 - Binary Tree Level Order Traversal
//
//  Created by Wu, Meng Ju on 2020/5/3.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> level;
        queue<pair<TreeNode*, int>> q;
        // pair<node, depth>
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, dep] = q.front();
            q.pop();
            if (node) {
                if (dep >= level.size())
                    level.push_back({});
                
                level[dep].push_back(node->val);
                
                q.push({node->left, dep+1});
                q.push({node->right, dep+1});
            }
        }
        return level;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
