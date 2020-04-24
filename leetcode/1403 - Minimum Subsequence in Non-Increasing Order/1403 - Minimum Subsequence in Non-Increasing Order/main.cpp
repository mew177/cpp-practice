//
//  main.cpp
//  1403 - Minimum Subsequence in Non-Increasing Order
//
//  Created by Wu, Meng Ju on 2020/4/17.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> rightNums;
        int leftSum = accumulate(nums.begin(), nums.end(), 0);
        int rightSum = 0;
        
        for (int i = nums.size()-1; i >= 0; i--) {
            leftSum -= nums[i];
            rightSum += nums[i];
            rightNums.push_back(nums[i]);
            
            if (leftSum < rightSum) {
                break;
            }
        }
        return rightNums;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
