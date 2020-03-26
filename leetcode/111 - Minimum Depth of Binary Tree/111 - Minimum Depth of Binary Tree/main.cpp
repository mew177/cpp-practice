//
//  main.cpp
//  111 - Minimum Depth of Binary Tree
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    TreeNode *node;
    int depth;
    
    Node(TreeNode *n, int d): node(n), depth(d) {}
};

class Solution {
private:
    int bfs(TreeNode* root) {
        int minDepth = 0;
        if (root == NULL) { return minDepth; }
        
        queue<Node> queue;
        queue.push(Node(root, minDepth+1));
        while (queue.size() > 0) {
            Node node = queue.front();
            queue.pop();
    
            if (node.node != NULL) {
                if (node.node->left == NULL && node.node->right == NULL) {
                    minDepth = node.depth;
                    break;
                } else {
                    if (node.node->left != NULL) { queue.push(Node(node.node->left, node.depth+1)); }
                    if (node.node->right != NULL) { queue.push(Node(node.node->right, node.depth+1)); }
                }
                
            }
        }
        return minDepth;
    }
    
public:
    int minDepth(TreeNode* root) {
        int depth = bfs(root);
        return depth;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
