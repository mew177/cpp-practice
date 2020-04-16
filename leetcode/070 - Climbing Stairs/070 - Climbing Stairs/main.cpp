//
//  main.cpp
//  070 - Climbing Stairs
//
//  Created by Wu, Meng Ju on 2020/4/10.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        
        if (n >= 1) {
            dp[1][0] = 1;
            dp[1][1] = 0;
        }
            
        if (n >= 2) {
            dp[2][0] = 1;
            dp[2][1] = 1;
        }
        
        if (n >= 3) {
            for (int i = 3; i < n+1; i++) {
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
                dp[i][1] = dp[i-2][0] + dp[i-2][1];
            }
        }
        return dp[n][0] + dp[n][1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
