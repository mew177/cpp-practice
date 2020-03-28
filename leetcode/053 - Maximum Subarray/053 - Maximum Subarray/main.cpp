//
//  main.cpp
//  053 - Maximum Subarray
//
//  Created by Wu, Meng Ju on 2020/3/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }
        
        int maxSum = nums[0];
        int subSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] + subSum >= nums[i]) {
                subSum = subSum + nums[i];
            } else {
                subSum = nums[i];
            }
            maxSum = max(maxSum, subSum);
        }
        
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
