//
//  main.cpp
//  075 - Sort Colors
//
//  Created by Wu, Meng Ju on 2020/4/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // two pointers
        int l = 0, r = nums.size()-1, curr = 0;
        
        while (curr <= r) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[l]);
                l++;
                curr++;
            } else if (nums[curr] == 2) {
                swap(nums[curr], nums[r]);
                r--;
            } else {
                curr++;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
