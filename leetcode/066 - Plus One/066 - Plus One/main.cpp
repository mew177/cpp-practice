//
//  main.cpp
//  066 - Plus One
//
//  Created by Wu, Meng Ju on 2020/5/8.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        
        for (int i = n-1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        
        if (!carry)
            return digits;
        vector<int> ans = {1};
        ans.insert(ans.end(), digits.begin(), digits.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
