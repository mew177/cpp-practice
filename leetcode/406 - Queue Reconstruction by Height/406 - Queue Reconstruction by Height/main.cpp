//
//  main.cpp
//  406 - Queue Reconstruction by Height
//
//  Created by Wu, Meng Ju on 2020/4/12.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(vector<int> &p1, vector<int> &p2) {
        if (p1[0] > p2[0]) {
            return false;
        } else if (p1[0] == p2[0]) {
            return p1[1] > p2[1];
        } else {
            return true;
        }
    }
    
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> queue;
        
        for (vector<int> person : people) {
            queue.push(person);
        }
        
        vector<vector<int>> line;
        while (!queue.empty()) {
            int i = 0;
            int infront = 0;
            while (i < line.size()) {
                if (infront == queue.top()[1]) {
                    break;
                }
                
                if (queue.top()[0] <= line[i][0]) {
                    infront += 1;
                    i += 1;
                }
            }
            vector<int> person = {queue.top()[0], queue.top()[1]};
            line.insert(line.begin()+i, person);
            queue.pop();
        }
        return line;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
