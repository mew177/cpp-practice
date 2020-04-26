//
//  main.cpp
//  1198 - Find Smallest Common Element in All Rows
//
//  Created by Wu, Meng Ju on 2020/4/25.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int N = mat.size();
        vector<int> ptr(N, 0);
        int C = mat[0].size();
        
        int maxInd = 0;
        bool match = true;
        while (maxInd < C) {
            match = true;
            for (int i = 0; i < N; i++) {
                if (mat[i][ptr[i]] < mat[(i+1) % N][ptr[(i+1) % N]]) {
                    ptr[i]++;
                    match = false;
                    maxInd = max(ptr[i], maxInd);
                    break;
                }
            }
            
            if (match) {
                //cout << "return " << mat[0][ptr[0]] << endl;
                return mat[0][ptr[0]];
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
