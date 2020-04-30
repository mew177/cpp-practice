//
//  main.cpp
//  063 - Unique Paths II
//
//  Created by Wu, Meng Ju on 2020/4/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    
    int dynamicProgramming(int R, int C, vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return 0;
        }
        
        vector<vector<long>> dp(R, vector<long>(C, 0));
        
        int k = 1;
        for (int i = 0; i < R; i++) {
            if (grid[i][0] == 1) { k = 0; }
            dp[i][0] = k;
        }
        
        k = 1;
        for (int j = 0; j < C; j++) {
            if (grid[0][j] == 1) { k = 0; }
            dp[0][j] = k;
        }
        
        
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[R-1][C-1];
    }
    
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();
        return dynamicProgramming(R, C, obstacleGrid);
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
