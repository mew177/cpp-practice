//
//  main.cpp
//  1167 - Minimum Cost to Connect Sticks
//
//  Created by Wu, Meng Ju on 2020/4/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int stick : sticks) { queue.push(stick); }
        
        int cost = 0;
        while (queue.size() > 1) {
            // combine first two
            int first = queue.top();
            queue.pop();
            int second = queue.top();
            queue.pop();
            int curr = first + second;
            cost += curr;
            queue.push(curr);
        }
        return cost;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
