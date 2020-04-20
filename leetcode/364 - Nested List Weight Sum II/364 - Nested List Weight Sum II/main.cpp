//
//  main.cpp
//  364 - Nested List Weight Sum II
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    void dfs(vector<NestedInteger>& nestedList, int depth, vector<vector<int>>& records, int& maxDep) {
        for (NestedInteger n : nestedList) {
            if (n.isInteger()) {
                vector<int> layer = {n.getInteger(), depth};
                records.push_back(layer);
                maxDep = max(maxDep, depth);
            } else {
                dfs(n.getList(), depth+1, records, maxDep);
            }
        }
    }
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDep = 0;
        vector<vector<int>> records;
        dfs(nestedList, 1, records, maxDep);
        
        int total = 0;
        for (vector<int> pair : records) {
            total += (pair[0] * (maxDep - pair[1] + 1));
        }
        return total;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
