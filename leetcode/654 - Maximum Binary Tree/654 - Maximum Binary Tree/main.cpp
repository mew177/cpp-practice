//
//  main.cpp
//  654 - Maximum Binary Tree
//
//  Created by Wu, Meng Ju on 2020/4/24.
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
    int maxIndex(vector<int>& nums, int i, int j) {
        if (i > j) return -1; // no element remain in subarray
        
        int idx = i;
        for (int k = i; k <= j; k++)
            if (nums[k] > nums[idx])
                idx = k;
        // return index of max number in subarray
        return idx;
    }
    
    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        // find the index of maximum
        int m = maxIndex(nums, l, r);
        // if no maximum found, no element in subarray
        if (m == -1) { return NULL; }
        TreeNode* node = new TreeNode(nums[m]);
        // right child construct by [m+1, r]
        node->right = buildTree(nums, m+1, r);
        // left child construct by [l, m-1]
        node->left  = buildTree(nums, l, m-1);
        return node;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
