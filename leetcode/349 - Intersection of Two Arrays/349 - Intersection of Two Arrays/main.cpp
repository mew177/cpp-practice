//
//  main.cpp
//  349 - Intersection of Two Arrays
//
//  Created by Wu, Meng Ju on 2020/3/31.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, bool> record;
        for(int num: nums1) {
            record[num] = true;
        }
        
        std::set<int> intersection;
        for(int num: nums2) {
            if (record.find(num) != record.end()) {
                intersection.insert(num);
            }
        }
        std::vector<int> ans(intersection.begin(), intersection.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
