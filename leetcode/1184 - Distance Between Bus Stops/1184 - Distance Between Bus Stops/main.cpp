//
//  main.cpp
//  1184 - Distance Between Bus Stops
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            int tmp = start;
            start = destination;
            destination = tmp;
        }
        int cw=0, ccw=0;
        
        for (int i = 0; i < distance.size(); i++) {
            if (i < start || i >= destination) {
                ccw += distance[i];
            } else {
                cw += distance[i];
            }
        }
        return min(ccw, cw);
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
