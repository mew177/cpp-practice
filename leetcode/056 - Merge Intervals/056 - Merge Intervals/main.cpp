//
//  main.cpp
//  056 - Merge Intervals
//
//  Created by Wu, Meng Ju on 2020/3/31.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct cmp {
  
    bool operator()(const vector<int>& i1, const vector<int>& i2) {
        return i1[0] > i2[0];
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.size() == 0) { return intervals; }
        
        priority_queue<vector<int>, vector<vector<int>>, cmp> queue;
        for(vector<int> itr: intervals) {
            queue.push(itr);
        }
        
        vector<vector<int>> newIntervals;
        newIntervals.push_back(queue.top());
        queue.pop();
        
        while (!queue.empty()) {
            if (newIntervals.back()[1] >= queue.top()[0]) {
                newIntervals.back()[1] = max(queue.top()[1], newIntervals.back()[1]);
            } else {
                newIntervals.push_back(queue.top());
            }
            queue.pop();
        }
        return newIntervals;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
