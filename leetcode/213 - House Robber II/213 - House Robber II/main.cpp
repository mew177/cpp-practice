//
//  main.cpp
//  213 - House Robber II
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return 0; }
        if (n == 1) { return nums[0]; }
        
        vector<int> start_first(n, 0);
        vector<int> start_second(n, 0);
        
        start_first[0] = nums[0];
        start_first[1] = max(nums[0], nums[1]);
        start_second[0] = 0;
        start_second[1] = nums[1];
        
        for (int i = 2; i < n; i++) {
            start_second[i] = max(start_second[i-1], start_second[i-2] + nums[i]);
            start_first[i] = max(start_first[i-1], start_first[i-2] + nums[i]);
        }
        
        return max(start_first[n-2], start_second[n-1]);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
