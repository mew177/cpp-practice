//
//  main.cpp
//  280 - Wiggle Sort
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
public:
    void wiggleSort(vector<int>& nums) {
        // solution 2
        // one way
        if (nums.size() == 0) {
            return ;
        }
        
        bool less = true;
        for (int i = 0; i < nums.size()-1; i++){
            if (less) {
                if (nums[i] > nums[i+1]) {
                    swap(nums, i, i+1);
                }
                
            } else {
                if (nums[i] < nums[i+1]) {
                    swap(nums, i, i+1);
                }
            }
            less = !less;
        }
        return;
        
        
        // solution 1
        // sort
        if (nums.size() == 0) {
            return ;
        }
        sort(nums.begin(), nums.end()); // nlogn
        for (int i = 1; i < nums.size()-1; i+=2) { // n
            swap(nums, i, i+1);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
