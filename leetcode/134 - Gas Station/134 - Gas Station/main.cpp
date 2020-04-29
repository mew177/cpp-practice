//
//  main.cpp
//  134 - Gas Station
//
//  Created by Wu, Meng Ju on 2020/4/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int curr_tank = 0;
        int start = 0;
            
        for (int i = 0; i < gas.size(); i++) {
            total_tank += (gas[i] - cost[i]);
            curr_tank += (gas[i] - cost[i]);

            if (curr_tank < 0) {
                // this is not a possible start point
                curr_tank = 0;
                start = i + 1;
            }
        }
        return total_tank >= 0 ? start : -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
