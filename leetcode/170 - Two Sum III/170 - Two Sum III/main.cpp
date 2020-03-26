//
//  main.cpp
//  170 - Two Sum III
//
//  Created by Wu, Meng Ju on 2020/3/25.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TwoSum {
    /*  A vector based structure
     *  insert sort when add a new number
     *  use two pointer from left and right to find pair
     */
    
public:
    vector<int> nums;
    
    /** Initialize your data structure here. */
    TwoSum() { }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if (nums.size() == 1) {
            nums.push_back(number);
        } else {
            
            for (int i = nums.size()-1; i >= 0; i--) {
                if (number > nums[i]) {
                    nums.insert(nums.begin()+i, number);
                    break;
                }
            }
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        int l = 0;
        int r = nums.size()-1;
        
        while (l < r) {
            if (nums[l] + nums[r] > value) { r--; }
            else if (nums[l] + nums[r] < value) { l++; }
            else { return true; }
        }
        return false;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
