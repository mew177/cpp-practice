//
//  main.cpp
//  881 - Boats to Save People
//
//  Created by Wu, Meng Ju on 2020/4/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // two pointer pointing to left and right
        int l = 0, r = people.size()-1;
        // sort people with weight
        sort(people.begin(), people.end());
        int boats = 0;
        
        while (l <= r) {
            boats++;
            if (people[l] + people[r] <= limit)
                l++;
            r--;
        }
        
        return boats;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
