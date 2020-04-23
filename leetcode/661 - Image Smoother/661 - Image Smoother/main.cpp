//
//  main.cpp
//  661 - Image Smoother
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions = {
        {0, 0},
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
        {-1, -1},
        {1, 1},
        {1, -1},
        {-1, 1}
    };
    
    int average(int x, int y, vector<vector<int>>& M) {
        int sum = 0;
        int cnt = 0;
        for (vector<int> direction : directions) {
            int X = direction[0] + x;
            int Y = direction[1] + y;
            if (0 <= X && X < M.size() && 0 <= Y && Y < M[0].size()) {
                sum += M[X][Y];
                cnt += 1;
            }
        }
        return sum != 0 ? (sum / cnt) : 0;
    }
    
public:
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> smooth;
        for (int i = 0; i < M.size(); i++) {
            vector<int> row;
            for(int j = 0; j < M[0].size(); j++) {
                int avg = average(int(i), int(j), M);
                row.push_back(avg);
            }
            smooth.push_back(row);
        }
        return smooth;
    }
    
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
