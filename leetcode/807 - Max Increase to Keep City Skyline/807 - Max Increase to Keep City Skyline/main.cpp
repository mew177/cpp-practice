//
//  main.cpp
//  807 - Max Increase to Keep City Skyline
//
//  Created by Wu, Meng Ju on 2020/4/24.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> rowMax(r, 0);
        vector<int> colMax(c, 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        
        int increase = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                increase += (min(rowMax[i], colMax[j]) - grid[i][j]);
            }
        }
        return increase;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
