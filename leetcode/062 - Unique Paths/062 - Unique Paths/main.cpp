//
//  main.cpp
//  062 - Unique Paths
//
//  Created by Wu, Meng Ju on 2020/4/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    
    int dynamicProgramming(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    
    /* Time Limit Exceeded */
    vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}
    };

    int iterative(int m, int n) {
        // pair<i_position, j_position>
        queue<pair<int, int>> q;
        q.push({0, 0});
        pair<int, int> goal = {m-1, n-1};
        int count = 0;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        
        while (!q.empty()) {
            pair<int, int> state = q.front();
            auto [i, j] = state;
            seen[i][j] = true;
            q.pop();
            if (state == goal) { count++; }
            else {
                for (auto [di, dj] : directions) {
                    pair<int, int> next = {di+i, dj+j};
                    if (0 <= di+i && di+i < m && 0 <= dj+j && dj+j < n && !seen[di+i][dj+j]) {
                        // is a valid move
                        q.push({di+i, dj+j});
                    }
                }
            }
        }
        return count;
    }
    
public:
    int uniquePaths(int m, int n) {
        
        return dynamicProgramming(m, n);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
