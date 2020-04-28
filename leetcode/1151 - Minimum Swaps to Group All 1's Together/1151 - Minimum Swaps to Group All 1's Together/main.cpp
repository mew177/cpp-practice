//
//  main.cpp
//  1151 - Minimum Swaps to Group All 1's Together
//
//  Created by Wu, Meng Ju on 2020/4/18.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int num_of_ones = 0;
        int num_of_zeros = 0;
        for (vector<int>::iterator it=data.begin(); it != data.end(); ++it) {
            if (*it == 1) { num_of_ones++; }
        }
        
        for (int i = 0; i < num_of_ones; i++) {
            if (data[i] == 0) { num_of_zeros++; }
        }
        
        int minSwap = num_of_zeros;
        for (int i = num_of_ones; i < data.size(); i++) {
            if (data[i] == 0) {
                num_of_zeros++;
            }
            if (data[i-num_of_ones] == 0) {
                num_of_zeros--;
            }
            if (minSwap > num_of_zeros) {
                minSwap = num_of_zeros;
            }
        }
        return minSwap;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
