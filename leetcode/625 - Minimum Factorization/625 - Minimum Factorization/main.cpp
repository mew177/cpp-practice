//
//  main.cpp
//  625 - Minimum Factorization
//
//  Created by Wu, Meng Ju on 2020/4/11.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 2) {
            return a;
        }
        
        long res = 0;
        long mul = 1;
        for (int f = 9; f >= 2; f--) {
            while (a % f == 0) {
                a /= f;
                res = mul * f + res;
                mul *= 10;
            }
        }
        
        if (a < 2 && res <= INT_MAX) {
            return res;
        } else {
            return 0;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
