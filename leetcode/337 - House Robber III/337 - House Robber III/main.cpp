//
//  main.cpp
//  337 - House Robber III
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    
    pair<int, int> dfs(TreeNode* root) {
        if (!root) { return {0, 0}; }
        auto left = dfs(root->left);    // dp from left tree
        auto right = dfs(root->right);  // dp from right tree
        // [prev value, prevprev value]
        int prev = left.first + right.first;    // accumulate prev value
        int prevprev = left.second + right.second;    // accumulate prev prev value
        return { max(prev, prevprev+root->val), prev };
    }
    
public:
    int rob(TreeNode* root) {
        auto [prev, prevprev] = dfs(root);
        return prev;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
