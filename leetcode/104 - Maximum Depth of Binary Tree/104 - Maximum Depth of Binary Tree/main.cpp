//
//  main.cpp
//  104 - Maximum Depth of Binary Tree
//
//  Created by Wu, Meng Ju on 2020/3/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct Node {
    TreeNode *node;
    int depth;
    
    Node(TreeNode *n, int d): node(n), depth(d) {}
};

class Solution {
private:
    // recursive based traversal
    int traverse1(TreeNode* root, int nowDepth=0) {
        if (root != NULL) {
            return max(traverse1(root->left, nowDepth+1), traverse1(root->right, nowDepth+1));
        } else {
            // reach tree leaf
            return nowDepth;
        }
    }
    
    // iterative based traversal
    int traverse2(TreeNode* root, int nowDepth=0) {
        if (root == NULL) { return 0; }
        
        queue<Node> queue;
        queue.push(Node(root, 1));
        int maxDepth = 1;
        
        while (queue.size() > 0) {
            Node node = queue.front();
            queue.pop();
            if (node.node != NULL) {
                // is not the leaf of tree
                maxDepth = max(maxDepth, node.depth);
                queue.push(Node(node.node->left, node.depth+1));
                queue.push(Node(node.node->right, node.depth+1));
            }
        }
        return maxDepth;
    }
    
public:
    int maxDepth(TreeNode* root) {
        int depth1 = traverse1(root);
        int depth2 = traverse1(root);
        return depth1;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
