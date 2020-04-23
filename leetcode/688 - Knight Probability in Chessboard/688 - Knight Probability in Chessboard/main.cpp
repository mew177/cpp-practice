//
//  main.cpp
//  688 - Knight Probability in Chessboard
//
//  Created by Wu, Meng Ju on 2020/4/18.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> directions = {
            {1, 2},
            {1, -2},
            {2, 1},
            {2, -1},
            {-1, 2},
            {-1, -2},
            {-2, 1},
            {-2, -1}
        };
        
        double dp[N][N];
        double dp2[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = 0.0;
        
        dp[r][c] = 1.0;
        for (int k = 0; k < K; k++) {
            // initialize dp2 matrix
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    dp2[i][j] = 0.0;
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (vector<int> d : directions) {
                        if (0 <= i+d[0] && i+d[0] < N && 0 <= j+d[1] && j+d[1] < N) {
                            dp2[i+d[0]][j+d[1]] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
            
            // copy dp2 to dp
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    dp[i][j] = dp2[i][j];
        }
        
        double sum = 0.0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                    sum += dp[i][j];
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
