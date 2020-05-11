//
//  main.cpp
//  046 - Permutations
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// use built-in function std::next_permutation
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        do {
            permutations.push_back(nums);
        } while ( std::next_permutation(nums.begin(), nums.end()) );
        
        return permutations;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
