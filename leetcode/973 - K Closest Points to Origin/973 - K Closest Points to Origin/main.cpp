//
//  main.cpp
//  973 - K Closest Points to Origin
//
//  Created by Wu, Meng Ju on 2020/4/13.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(vector<int>& p1, vector<int>& p2) {
        int dist1 = p1[0] * p1[0] + p1[1] * p1[1];
        int dist2 = p2[0] * p2[0] + p2[1] * p2[1];
        return dist1 > dist2;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> queue;
        vector<vector<int>> res;
        for (vector<int> point : points) {
            queue.push(point);
        }
        
        for (int i = 0; i < K; i++) {
            res.push_back(queue.top());
            queue.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
