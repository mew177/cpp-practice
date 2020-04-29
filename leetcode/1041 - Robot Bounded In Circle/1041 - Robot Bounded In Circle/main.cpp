//
//  main.cpp
//  1041 - Robot Bounded In Circle
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> location = make_pair(0, 0);
        vector<pair<int, int>> direction;
        direction.push_back(make_pair(0, 1));   // North
        direction.push_back(make_pair(-1, 0));  // West
        direction.push_back(make_pair(0, -1));  // South
        direction.push_back(make_pair(1, 0));   // East
        int i = 0; // denoted as the direction facing
        for (int r = 0; r < 4; r++) {  // four rounds
            for (auto it: instructions) {
                if (it == 'G') {
                    location.first += direction[i].first;
                    location.second += direction[i].second;
                } else if (it == 'L'){
                    i = ((i-1) + 4) % 4;
                } else {
                    i = ((i+1) + 4) % 4;
                }
            }
        }
        
        // if location is (0, 0) and facing is north
        if (location.first == 0 && location.second == 0 && i == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
