//
//  main.cpp
//  133 - Clone Graph
//
//  Created by Wu, Meng Ju on 2020/4/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    
    map<Node*, Node*> seen;
    
public:
    Node* cloneGraph(Node* node) {
        
        if (!node) { return node; }
        
        if (seen.find(node) != seen.end()) {
            return seen[node];
        }
        
        Node* cloned = new Node();
        cloned->val = node->val;
        seen[node] = cloned;
        
        vector<Node*> cloned_neighbors;
        for (Node* child : node->neighbors) {
            cloned_neighbors.push_back(cloneGraph(child));
        }
        cloned->neighbors = cloned_neighbors;
        return cloned;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
