//
//  main.cpp
//  1150 - Check If a Number Is Majority Element in a Sorted Array
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count > 0 && nums[i] != target) {
                break;
            }
            
            if (count >= 0 && nums[i] == target) {
                count++;
            }
            
            // this reduce time complexity a lot
            if (count == 0 && i > nums.size()/2 ) {
                break;
            }
        }
        return count > nums.size()/2;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
