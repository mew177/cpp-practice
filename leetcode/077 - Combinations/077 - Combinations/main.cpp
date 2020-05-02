//
//  main.cpp
//  077 - Combinations
//
//  Created by Wu, Meng Ju on 2020/4/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    
    void backtracking(const int start, const int k, const int n, vector<int>& path, vector<vector<int>>& combinations) {
        if (path.size() == k) {
            // if this path has size k
            combinations.push_back(path);
            return;
        }
    
        for (int i = start; i < n+1; i++) {
            path.push_back(i);
            backtracking(i+1, k, n, path, combinations);
            path.erase(path.end()-1);
        }
        
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> path;
        
        backtracking(1, k, n, path, combinations);
        return combinations;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
