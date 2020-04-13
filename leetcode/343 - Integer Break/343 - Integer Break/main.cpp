//
//  main.cpp
//  343 - Integer Break
//
//  Created by Wu, Meng Ju on 2020/4/12.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> record(n+1, 0);
        record[0] = 0;
        record[1] = 1;
        int temp = 0;
        for (int i = 2; i < n+1; i++) {
            temp = 0;
            for (int j = 1; j <= i/2; j++) {
                int prod = max(j, record[j]) * max(i-j, record[i-j]);
                temp = max(temp, prod);
            }
            record[i] = temp;
        }
        return record[n];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
