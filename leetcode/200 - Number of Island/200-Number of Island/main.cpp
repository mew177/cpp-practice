//
//  main.cpp
//  200-Number of Island
//
//  Created by Wu, Meng Ju on 2020/3/25.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class numIslands {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        int r = grid.size();
        int c = grid[0].size();
        
        if (i-1 >= 0 && grid[i-1][j] == '1') { dfs(grid, i-1, j); }
        if (i+1 < r && grid[i+1][j] == '1') { dfs(grid, i+1, j); }
        if (j-1 >= 0 && grid[i][j-1] == '1') { dfs(grid, i, j-1); }
        if (j+1 < c && grid[i][j+1] == '1') { dfs(grid, i, j+1); }
    }

public:
    int solution(vector<vector<char>>& grid) {
        
        int nr = grid.size();
        if (!nr) {
            return 0;
        }
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
          for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
              ++num_islands;
              dfs(grid, r, c);
            }
          }
        }

        return num_islands;
        
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
