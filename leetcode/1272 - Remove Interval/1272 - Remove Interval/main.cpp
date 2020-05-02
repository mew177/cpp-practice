//
//  main.cpp
//  1272 - Remove Interval
//
//  Created by Wu, Meng Ju on 2020/4/24.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        // Four cases
        // 1. removed interval [x, y] overlapped with [a, b] where x <= b <= y
        // [a, b] -> [a, x]
        // 2. removed interval [x, y] overlapped with [a, b] where x <= a <= y
        // [a, b] -> [y, b]
        // 3. removed interval [x, y] overlapped with [a, b] where x <= a <= b <= y
        // [a, b] -> None
        // 4. removed interval [x, y] overlapped with [a, b] where a <= x <= y <= b
        // [a, b] -> [a, x], [y, b]
        
        int x = toBeRemoved[0], y = toBeRemoved[1];
        vector<vector<int>> removed;
        for(vector<int> interval : intervals) {
            int a = interval[0], b = interval[1];
            if (a >= y || b <= x) {
                removed.push_back(interval);
                continue;
            } else if ( x <= a && y < b ) {
                removed.push_back({y, b});
            } else if ( a < x && b <= y ) {
                removed.push_back({a, x});
            } else if (a < x && b > y) {
                removed.push_back({a, x});
                removed.push_back({y, b});
            }
        }
        return removed;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
