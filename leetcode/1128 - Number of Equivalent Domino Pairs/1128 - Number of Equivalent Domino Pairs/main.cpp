//
//  main.cpp
//  1128 - Number of Equivalent Domino Pairs
//
//  Created by Wu, Meng Ju on 2020/4/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<string, int> pairs;
        
        for (vector<int> domino : dominoes) {
            int x=domino[0], y=domino[1];
            string pair1=to_string(x)+to_string(y), pair2=to_string(y)+to_string(x);
            
            if (pairs.find(pair1) != pairs.end()) {
                pairs[pair1] += 1;
            } else if (pairs.find(pair2) != pairs.end()) {
                pairs[pair2] += 1;
            } else {
                pairs[pair1] = 1;
            }
        }
        
        int count = 0;
        for (map<string, int>::iterator it=pairs.begin(); it != pairs.end(); ++it) {
            if (it->second > 1) {
                count += ((it->second * (it->second - 1)) / 2);
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
