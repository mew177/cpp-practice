//
//  main.cpp
//  1302 - Deepest Leaves Sum
//
//  Created by Wu, Meng Ju on 2020/4/24.
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        vector<int> sum;
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (node) {
                if (depth > sum.size())
                    sum.push_back(node->val);
                else
                    sum[depth-1] += node->val;
                q.push({node->left, depth+1});
                q.push({node->right, depth+1});
            }
        }
        return sum.back();
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
