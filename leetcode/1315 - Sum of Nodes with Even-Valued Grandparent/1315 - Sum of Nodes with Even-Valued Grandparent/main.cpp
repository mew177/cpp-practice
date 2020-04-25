//
//  main.cpp
//  1315 - Sum of Nodes with Even-Valued Grandparent
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
    int sumEvenGrandparent(TreeNode* root) {
        // pair<node, <parent, grandParent>>
        queue<pair<TreeNode*, pair<bool, bool>>> q;
        // root node has no parent
        q.push({root, {false, false}});
        int sum = 0;
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            bool parent = q.front().second.first;
            bool grand = q.front().second.second;
            q.pop();
            if (node) {
                // add to sum if toADD is true
                if (grand) { sum += node->val; }
                // if node->val is even change toADD = true
                grand = parent;
                parent = node->val % 2 == 0 ? true : false;
                q.push({node->left, {parent, grand}});
                q.push({node->right, {parent, grand}});
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
