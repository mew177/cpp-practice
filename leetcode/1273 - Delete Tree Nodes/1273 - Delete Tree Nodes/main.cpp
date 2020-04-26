//
//  main.cpp
//  1273 - Delete Tree Nodes
//
//  Created by Wu, Meng Ju on 2020/4/25.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    
    void removeSubtree(map<int, vector<int>>& graph, int root) {
        for (int child : graph[root])
            removeSubtree(graph, child);
        graph.erase(root);
    }
    
    int dfs(map<int, vector<int>>& graph, vector<int>& value, int root) {
        int sum = value[root];
        for (int child : graph[root])
            // add total sum from each child
            sum += dfs(graph, value, child);
        // if sum == 0, remove this subtree
        if (sum == 0) removeSubtree(graph, root);
        // return sum back to parent
        return sum;
    }
    
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        map<int, vector<int>> graph;
        for (int p : parent) { graph[p] = vector<int>(); }
        for (int i = 0; i < value.size(); i++)
            // build graph
            graph[parent[i]].push_back(i);
        
        dfs(graph, value, 0);
        graph.erase(-1);
        return graph.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
