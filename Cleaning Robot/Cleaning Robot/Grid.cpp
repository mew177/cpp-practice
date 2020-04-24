//
//  Grid.cpp
//  Cleaning Robot
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Grid {
private:
    vector<vector<int>> grid;
    
public:
    
    Grid() {
        grid = vector<vector<int>>(10, vector<int>(10, 0));
        grid[4][4] = 1;
    };
    
    Grid(vector<vector<int>>& grid): grid(grid) {
        
    };
    
    ~Grid() {
        
    };
    
    void clean(int x, int y) {
        grid[x][y] = -1;
    };
    
    bool stuck(int x, int y) {
        if (x < 0 or x >= grid.size()) { return true; }
        if (y < 0 or y >= grid[0].size()) { return true; }
        return grid[x][y] == 1;
    }
    
    bool check() {
        for (vector<int> row : grid) {
            for (vector<int>::iterator it=row.begin(); it!=row.end(); ++it) {
                cout << *it << ' ' ;
                if (*it == 0) {
                    cout << "Room is still dirty!" << endl;
                    return false;
                }
            }
            cout << endl;
        }
        cout << "Room is completely cleaned!" << endl;
        return true;
    }
    
    void print() {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                cout << grid[i][j] << '\t';
            }
            cout << endl;
        }
    }
};
