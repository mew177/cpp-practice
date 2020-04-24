//
//  main.cpp
//  222 - Count Complete Tree Nodes
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
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
    int countNodes(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* next = q.front();
            q.pop();
            if (next != NULL) {
                cnt++;
                q.push(next->left);
                q.push(next->right);
            }
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
