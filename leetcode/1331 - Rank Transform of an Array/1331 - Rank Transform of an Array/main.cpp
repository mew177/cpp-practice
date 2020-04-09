//
//  main.cpp
//  1331 - Rank Transform of an Array
//
//  Created by Wu, Meng Ju on 2020/4/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank = 1;
        vector<int> copy;
        for (int num : arr) {
            copy.push_back(num);
        }
        sort(arr.begin(), arr.end());
        map<int, int> ranks;
        for (int num : arr) {
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = rank++;
            }
        }
        
        vector<int> ranking;
        for (int num : copy) {
            ranking.push_back(ranks[num]);
        }
        return ranking;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
