//
//  main.cpp
//  073 - Set Matrix Zeroes
//
//  Created by Wu, Meng Ju on 2020/4/3.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x, y;
    point(int x, int y): x(x), y(y) {}
};

class Solution {
private:
    void setRowZeros(vector<vector<int>>& matrix, int row) {
        for (int i = 0; i < matrix[row].size(); i++) {
            matrix[row][i] = 0;
        }
    }
    
    void setColZeros(vector<vector<int>>& matrix, int col) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][col] = 0;
        }
    }
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<point*> zeros;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zeros.push_back(new point(i, j));
                }
            }
        }
        
        for(point* p : zeros) {
            setRowZeros(matrix, p->x);
            setColZeros(matrix, p->y);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
