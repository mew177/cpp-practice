//
//  main.cpp
//  096 - Unique Binary Search Trees
//
//  Created by Wu, Meng Ju on 2020/4/11.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i < n+1; i++) {
            dp[i] = 0;
            for (int j = 1; j < i+1; j++) {
                dp[i] += (dp[j-1] * dp[i-j]);
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
