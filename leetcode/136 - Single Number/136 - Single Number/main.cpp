//
//  main.cpp
//  136 - Single Number
//
//  Created by Wu, Meng Ju on 2020/3/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, bool> table;
        
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(nums[i]) != table.end()) {
                table.erase(nums[i]);
            } else {
                table[nums[i]] = true;
            }
        }
        int duplicated = 0;
        for (map<int, bool>::iterator it = table.begin(); it != table.end(); ++it) {
            duplicated = it->first;
        }
        return duplicated;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
