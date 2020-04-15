//
//  main.cpp
//  055 - Jump Game
//
//  Created by Wu, Meng Ju on 2020/4/12.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i <= furthest) {
                furthest = max(furthest, i+nums[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
