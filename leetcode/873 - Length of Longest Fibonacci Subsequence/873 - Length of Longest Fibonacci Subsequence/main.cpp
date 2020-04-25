//
//  main.cpp
//  873 - Length of Longest Fibonacci Subsequence
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        map<int, int> indexes;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int i = 0; i < n; i++) { indexes[A[i]] = i; }
        
        int ans = 0;
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                int x = A[j], y = A[k];
                if (indexes.count(y-x) == 1) {
                    int i = indexes[y-x];
                    if (i < j) {
                        dp[j][k] = dp[i][j] + 1;
                        ans = max(ans, dp[j][k]);
                    }
                }
            }
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
