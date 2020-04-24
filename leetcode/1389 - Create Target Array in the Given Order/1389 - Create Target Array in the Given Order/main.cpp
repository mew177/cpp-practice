//
//  main.cpp
//  1389 - Create Target Array in the Given Order
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> sorted;
        for (int i = 0; i < nums.size(); i++) {
            sorted.insert(sorted.begin() + index[i], nums[i]);
        }
        
        return sorted;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
