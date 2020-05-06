//
//  main.cpp
//  404 - Sum of Left Leaves
//
//  Created by Wu, Meng Ju on 2020/5/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
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
private:
    void aggregate(TreeNode* root, int* sum) {
        if (root) {
            if (root->left && !root->left->right && !root->left->left)
                // if left child is a leaf
                (*sum) += (root->left->val);
            aggregate(root->left, sum);
            aggregate(root->right, sum);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        aggregate(root, &sum);
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
