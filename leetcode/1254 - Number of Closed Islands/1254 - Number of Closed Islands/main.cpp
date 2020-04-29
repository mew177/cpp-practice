//
//  main.cpp
//  1254 - Number of Closed Islands
//
//  Created by Wu, Meng Ju on 2020/4/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
    vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    
    bool isValid(int r, int c, int R, int C) {
        if (r >= 0 && r < R && c >= 0 && c < C)
            return true;
        else
            return false;
    }
    
    bool dfs(vector<vector<int>>& grid, int R, int C, int r, int c, vector<vector<int>>& visited) {
        // if reaching parimeter and it's 0
        if ((r == 0 || r == R-1 || c == 0 || c == C-1) && grid[r][c] == 0)
            return false;
        if (grid[r][c] == 1)
            return true;
        
        visited[r][c] = true;
        bool ans = true;
        for (pair<int, int> direction : directions) {
            auto [dr, dc] = direction;
            if (isValid(dr+r, dc+c, R, C) && !visited[dr+r][dc+c]) {
                ans &= dfs(grid, R, C, dr+r, dc+c, visited);
            }
        }
        return ans;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> visited(R, vector<int>(C, false));
        int count = 0;
        
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (grid[r][c] == 0)
                    if (!visited[r][c] && dfs(grid, R, C, r, c, visited))
                        count++;
        
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
