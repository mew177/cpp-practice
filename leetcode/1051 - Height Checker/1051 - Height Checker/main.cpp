//
//  main.cpp
//  1051 - Height Checker
//
//  Created by Wu, Meng Ju on 2020/3/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    // find bit difference with sorted heights
    int heightChecker(vector<int>& heights) {
        priority_queue<int, vector<int>, greater<int>> sorted;
        
        for (int i = 0; i < heights.size(); i++) {
            sorted.push(heights[i]);
        }
        
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted.top()) {
                count += 1;
            }
            sorted.pop();
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
