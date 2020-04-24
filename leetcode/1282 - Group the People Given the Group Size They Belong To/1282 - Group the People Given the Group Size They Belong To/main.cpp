//
//  main.cpp
//  1282 - Group the People Given the Group Size They Belong To
//
//  Created by Wu, Meng Ju on 2020/4/21.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> groups;
        vector<vector<int>> ans;
        
        for (int i = 0; i < groupSizes.size(); i++) {
            groups[groupSizes[i]].push_back(i);
            if (groups[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(groups[groupSizes[i]]);
                groups[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
