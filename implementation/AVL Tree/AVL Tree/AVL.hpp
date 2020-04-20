//
//  AVL.hpp
//  AVL Tree
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#ifndef AVL_hpp
#define AVL_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    int h;
    int bf;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v): val(v), bf(0), h(0), left(NULL), right(NULL) { };
};

class AVL {
private:
    
    TreeNode* _insert(TreeNode*, int);
    void _update(TreeNode*);
    TreeNode* _balance(TreeNode*);
    
    // rotation function
    
    TreeNode* leftLeftCase(TreeNode*);
    TreeNode* leftRightCase(TreeNode*);
    TreeNode* rightRightCase(TreeNode*);
    TreeNode* rightLeftCase(TreeNode*);
    
public:
    TreeNode* root;
    AVL();
    ~AVL();
    void insert(int);
    void traverse();
    void print();
    
    TreeNode* leftRotate(TreeNode*);
    TreeNode* rightRotate(TreeNode*);
};

#endif /* AVL_hpp */
