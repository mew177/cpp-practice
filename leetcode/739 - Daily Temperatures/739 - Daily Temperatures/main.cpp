//
//  main.cpp
//  739 - Daily Temperatures
//
//  Created by Wu, Meng Ju on 2020/5/2.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // pair<temperature, index>
        stack<pair<int, int>> record;
        record.push({T.back(), T.size()-1});
        vector<int> ans(T.size(), 0);
        for (int i = T.size()-1; i >= 0; i--) {
            while (!record.empty() && T[i] >= record.top().first)
                // pop if top element has no higher temperature than today
                record.pop();
            
            if (record.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = record.top().second - i;
            }
            record.push({T[i], i});
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
