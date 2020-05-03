//
//  main.cpp
//  074 - Search a 2D Matrix
//
//  Created by Wu, Meng Ju on 2020/4/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();
        if (R == 0) return 0;
        int C = matrix[0].size();
        if (C == 0) return 0;
        
        int l = 0, r = R * C - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (matrix[m / C][m % C] == target)
                return true;
            else {
                if (matrix[m / C][m % C] > target)
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
