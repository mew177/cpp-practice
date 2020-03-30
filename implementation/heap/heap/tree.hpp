//
//  tree.hpp
//  heap
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Tree {
private:
    void _insert(TreeNode*, int);
    void _preorder(TreeNode*);
    void _postorder(TreeNode*);
    void _inorder(TreeNode*);
    void _destroy(TreeNode*);
    bool _find(TreeNode*, int);
    std::vector<TreeNode*> _heapify(TreeNode* root);
    
public:
    // parameters
    TreeNode *root;
    int size;
    
    // constructor
    Tree();
    ~Tree();
    
    // functions
    void destroy();
    void insert(int);
    void remove(int);
    bool find(int);
    void inorder();
    void postorder();
    void preorder();
    std::vector<TreeNode*> heapify();
    
};

#endif /* tree_hpp */
