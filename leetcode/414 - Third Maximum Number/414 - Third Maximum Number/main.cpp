//
//  main.cpp
//  414 - Third Maximum Number
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    int popMax(vector<int>& nums) {
        int maximum = INT_MIN;
        for (int num : nums) {
            if (maximum < num) {
                maximum = num;
            }
        }
        
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); ++it) {
            if (maximum == *it) {
                nums.erase(it);
                break;
            }
        }
        
        return maximum;
    }
    
public:
    int thirdMax(vector<int>& nums) {
        set<int> numbers;
        for (int num : nums) {
            numbers.insert(num);
        }
        nums.clear();
        for (set<int>::iterator it=numbers.begin(); it != numbers.end(); ++it) {
            nums.push_back(*it);
        }
        
        if (nums.size() < 3) {
            return popMax(nums);
        }
        
        popMax(nums);
        popMax(nums);
        return popMax(nums);
        
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
