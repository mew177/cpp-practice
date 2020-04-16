//
//  main.cpp
//  643 - Maximum Average Subarray I
//
//  Created by Wu, Meng Ju on 2020/4/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr = 0;
        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }
        
        int maxSum = curr;
        
        for (int i = k; i < nums.size(); i++) {
            curr = curr - nums[i-k] + nums[i];
            maxSum = max(maxSum, curr);
            cout << curr << endl;
            
        }
        
        return double(maxSum) / k;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
