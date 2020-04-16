//
//  main.cpp
//  683 - K Empty Slots
//
//  Created by Wu, Meng Ju on 2020/4/14.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        int N = bulbs.size();
        int lights[N];
        map<int, int> record;
        for (int i = 0; i < N; i++) {
            // initialize array with zeros
            lights[i] = 0;
        }
        
        for (int day = 0; day < bulbs.size(); day++) {
            int i = bulbs[day]-1;
            if (record.find(i) != record.end()) {
                bool turnedoff = true;
                for (int chk = min(record[i], i) + 1; chk < max(record[i], i); chk++) {
                    if (lights[chk] == 1) {
                        turnedoff = false;
                        break;
                    }
                }
                if (turnedoff) {
                    return day + 1; // days
                }
            }
            lights[i] = 1;
            record[i+K+1] = i;
            record[i-K-1] = i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
