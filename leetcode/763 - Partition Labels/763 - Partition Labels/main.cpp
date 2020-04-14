//
//  main.cpp
//  763 - Partition Labels
//
//  Created by Wu, Meng Ju on 2020/4/12.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct cmp {
    bool operator()(vector<int>& int1, vector<int>& int2) {
        return int1[0] > int2[0];
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, vector<int>> maps;
        for (int i = 0; i < S.size(); i++) {
            if (maps.find(S[i]) != maps.end()) {
                maps[S[i]][1] = i;
            } else {
                maps[S[i]] = {i, i};
            }
        }
        
        vector<vector<int>> intervals;
        priority_queue<vector<int>, vector<vector<int>>, cmp> queue;
        for (map<char, vector<int>>::iterator it = maps.begin(); it != maps.end(); ++it) {
            queue.push({it->second[0], it->second[1]});
        }
        
        vector<int> res;
        intervals.push_back({0, 0});
        while (!queue.empty()) {
            if (queue.top()[0] <= intervals[intervals.size()-1][1]) {
                intervals[intervals.size()-1][1] = max(queue.top()[1], intervals[intervals.size()-1][1]);
            } else {
                res.push_back(intervals[intervals.size()-1][1]-intervals[intervals.size()-1][0]+1);
                intervals.push_back({queue.top()[0], queue.top()[1]});
            }
            queue.pop();
        }
        res.push_back(intervals[intervals.size()-1][1]-intervals[intervals.size()-1][0]+1);
        
        return res;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
