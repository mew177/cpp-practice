//
//  main.cpp
//  565 - Array Nesting
//
//  Created by Wu, Meng Ju on 2020/4/17.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        set<int> seen;
        map<int, int> mapper;
        for (int i = 0; i < nums.size(); i++) {
            mapper[i] = nums[i];
        }
        
        int maxLeng = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int count = 0;
            while (seen.find(num) == seen.end()) {
                seen.insert(num);
                num = mapper[num];
                count += 1;
            }
            maxLeng = max(maxLeng, count);
        }
        return maxLeng;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
