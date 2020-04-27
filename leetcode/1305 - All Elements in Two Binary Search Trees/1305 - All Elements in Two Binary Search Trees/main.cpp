//
//  main.cpp
//  1305 - All Elements in Two Binary Search Trees
//
//  Created by Wu, Meng Ju on 2020/4/26.
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
    
    void inorder(vector<int>& ordered, TreeNode* root, int* i) {
        if (root) {
            inorder(ordered, root->left, i);
            if ((*i) == -1) {
                ordered.push_back(root->val);
                (*i)++;
            } else {
                while ((*i) < ordered.size() && ordered[(*i)] < root->val) {
                    (*i)++;
                }
                ordered.insert(ordered.begin() + (*i), root->val);
            }
            inorder(ordered, root->right, i);
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ordered;
        int i = -1;
        inorder(ordered, root1, &i);
        i = 0;
        inorder(ordered, root2, &i);
        return ordered;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
