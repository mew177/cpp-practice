//
//  main.cpp
//  566 - Reshape the Matrix
//
//  Created by Wu, Meng Ju on 2020/4/18.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int baseR = int(nums.size());
        int baseC = int(nums[0].size());
        if (baseR * baseC != r * c) { return nums; }
        
        // resultant matrix
        vector<vector<int>> reshaped(r, vector<int> (c, 0));
        int idx = 0;
        for (int i = 0; i < baseR; i++) {
            for (int j = 0; j < baseC; j++) {
                reshaped[idx / c][idx % c] = nums[i][j];
                idx++;
            }
        }
        return reshaped;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
