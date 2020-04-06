//
//  main.cpp
//  035 - Search Insert Position
//
//  Created by Wu, Meng Ju on 2020/4/5.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (target <= nums[i]) {
                return i;
            }
        }
        return int(nums.size());
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
