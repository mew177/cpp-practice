//
//  main.cpp
//  338 - Counting Bits
//
//  Created by Wu, Meng Ju on 2020/5/3.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> dp = {0, 1};
        
        while (dp.size() <= num) {
            vector<int> next_dp(dp.begin(), dp.end());
            for (vector<int>::iterator it=next_dp.begin(); it!=next_dp.end(); ++it)
                (*it)++;
            dp.insert(dp.end(), next_dp.begin(), next_dp.end());
        }
        return vector<int> (dp.begin(), dp.begin()+num+1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
