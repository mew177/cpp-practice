//
//  main.cpp
//  001-Two Sum
//
//  Created by Wu, Meng Ju on 2020/3/25.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class solution {
private:
    
public:
    // nested for loop
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i]+nums[j] == target) {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                }
            }
        }
        return ans;
    }
    
    // using map
    vector<int> twoSum2(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> ans;
    
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(nums[i]) != table.end()) {
                ans.push_back(table[nums[i]]);
                ans.push_back(i);
                break;
            } else { table[target-nums[i]] = i; }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
