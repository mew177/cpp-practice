//
//  main.cpp
//  994 - Rotting Oranges
//
//  Created by Wu, Meng Ju on 2020/3/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
    int x, y, r;
    point(int a, int b, int c): x(a), y(b), r(c) {}
};

class Solution {
private:
    int _bfs_queue(queue<point*>& q, vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int round = 0;
        
        while (!q.empty()) {
            point node = *(q.front());
            q.pop();
            int i = node.x, j = node.y;
            round = node.r;
            
            if (i+1 < r && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                q.push(new point(i+1, j, round+1));
            }
            if (j+1 < c && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                q.push(new point(i, j+1, round+1));
            }
            if (i-1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                q.push(new point(i-1, j, round+1));
            }
            if (j-1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                q.push(new point(i, j-1, round+1));
            }
        }
        return round;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<point*> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(new point(i, j, 0));
                }
            }
        }
        
        int round = _bfs_queue(q, grid);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return round;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
