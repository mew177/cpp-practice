//
//  main.cpp
//  697 - Degree of an Array
//
//  Created by Wu, Meng Ju on 2020/4/10.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct degree {
    int number;
    int start;
    int end;
    int count;
    
    degree(int num, int i): number(num), start(i), end(i), count(1) {}
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, degree*> index;
        int maxFreq = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (index.find(nums[i]) != index.end()) {
                index[nums[i]]->end = i;
                index[nums[i]]->count += 1;
            } else {
                index[nums[i]] = new degree(nums[i], i);
            }
            
            if (maxFreq < index[nums[i]]->count) {
                maxFreq = index[nums[i]]->count;
            }
            
        }
        int minLeng = INT_MAX;
        for (map<int, degree*>::iterator it=index.begin(); it != index.end(); ++it) {
            if (it->second->count == maxFreq) {
                minLeng = min(minLeng, (it->second->end - it->second->start + 1));
            }
        }
        return minLeng;
    }
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
