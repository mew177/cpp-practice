//
//  main.cpp
//  662 - Maximum Width of Binary Tree
//
//  Created by Wu, Meng Ju on 2020/3/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
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
    void _dfs(TreeNode *node, int *ans, int lvl, int idx, map<int, int> &record) {
        if (node != NULL) {
            //cout << "visiting: " << node->val << endl;
            if (record.find(lvl) != record.end()) {
                *ans = max(*ans, idx - record[lvl] + 1);
            } else {
                record[lvl] = idx;
            }
            _dfs(node->left, ans, lvl+1, idx*2+1, record);
            _dfs(node->right, ans, lvl+1, idx*2+2, record);
        }
    }
    
public:
    map<int, int> record;
    int *ans = new int(1);
    
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        _dfs(root, ans, 1, 0, record);
        return *ans;
    }
    
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
