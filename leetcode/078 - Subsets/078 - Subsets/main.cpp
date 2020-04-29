//
//  main.cpp
//  078 - Subsets
//
//  Created by Wu, Meng Ju on 2020/4/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    
    void bfs(const int index, vector<int>& nums, vector<int>& set, vector<vector<int>>& subsets) {
        if (index > nums.size()-1) {
            subsets.push_back(set);
            return;
        }
        
        vector<int> set_add = vector<int>(set.begin(), set.end());
        set_add.push_back(nums[index]);
        bfs(index+1, nums, set_add, subsets);
        bfs(index+1, nums, set, subsets);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> set;
        bfs(0, nums, set, subsets);
        return subsets;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
