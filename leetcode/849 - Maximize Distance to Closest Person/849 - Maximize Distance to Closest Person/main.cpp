//
//  main.cpp
//  849 - Maximize Distance to Closest Person
//
//  Created by Wu, Meng Ju on 2020/4/2.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        // search from left to right and right to right
        // combine two list with min
        // find max
        
        int size = seats.size();
        int left2right[size];
        int right2left[size];
        
        int dist = 20000;
        for (int i = 0; i < size; i++) {
            dist += 1;
            if (seats[i] == 1) { dist = 0; }
            left2right[i] = dist;
        }
        
        dist = 20000;
        for (int i = size-1; i >= 0; i--) {
            dist += 1;
            if (seats[i] == 1) { dist = 0; }
            right2left[i] = dist;
        }
        
        int maxDist = 0;
        for (int i = 0; i < size; i++) {
            maxDist = max(maxDist, min(left2right[i], right2left[i]));
        }
        return maxDist;
        
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
