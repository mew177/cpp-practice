//
//  main.cpp
//  Kahn's Algorithm
//
//  Created by Wu, Meng Ju on 2020/4/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Graph {
    map<char, vector<char>> g;
    Graph() {}
    
    void insert(char start, char end) {
        g[start].push_back(end);
    }
    
    void remove(char location) {
        g.erase(location);
    }
    
    bool hasIncomingNode(char location) {
        for (map<char, vector<char>>::iterator it=g.begin(); it!=g.end(); ++it) {
            for (char neighbor : it->second) {
                if (neighbor == location) {
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<char>& neighbors(char location) {
        return g[location];
    }
    
    bool empty() {
        return g.size() == 0;
    }
};


int main(int argc, const char * argv[]) {
    
    vector<pair<char, char>> edges = {
        {'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'E'},
        {'D', 'G'}, {'D', 'E'}, {'E', 'F'}, {'G', 'H'}, {'F', 'G'},
        {'I', 'J'}, {'J', 'K'}, {'J', 'L'}, {'K', 'C'}, {'L', 'M'},
        {'M', 'F'}, {'M', 'H'}, {'H', '#'}, {'M', 'C'}};
    
    Graph graph;
    for (auto [start, end] : edges)
        graph.insert(start, end);
    
    /* start algorithm */
    
    vector<char> next;  // this store the vertex which has no other vertex comes in
    vector<char> nodes = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
    
    for (char node : nodes)
        if (!graph.hasIncomingNode(node))
            // if this vertex has no incoming nodes
            next.push_back(node);
    
    string order = "";
    
    while (!graph.empty()) {
        // deal with the first vertex in next
        char node = next.front();
        next.erase(next.begin());
        
        // first simply put this vertex into order list
        order += node;
        // keep record with its neighbors
        vector<char> neighbors = graph.neighbors(node);
        // remove this node from graph
        graph.remove(node);
        // check whether it's neighbor become a vertex which has no incoming node
        for (char neighbor : neighbors)
            if (!graph.hasIncomingNode(neighbor))
                // if a neighbor has no incoming node, put it into next
                next.push_back(neighbor);
    }
    
    cout << order << endl;
    
    return 0;
}
