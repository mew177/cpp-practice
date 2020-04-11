//
//  main.cpp
//  072 - Edit Distance
//
//  Created by Wu, Meng Ju on 2020/4/10.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = int(word1.size());
        int n = int(word2.size());
        int dp[m+1][n+1];
        
        for (int i = 0; i < m+1; i++) {
            dp[i][0] = i;
        }
        
        for (int j = 0; j < n+1; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                int t1 = dp[i-1][j] + 1;
                int t2 = dp[i][j-1] + 1;
                int t3 = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1]) {
                    t3 += 1;
                }
                dp[i][j] = min(min(t1, t2), t3);
            }
        }
        
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
