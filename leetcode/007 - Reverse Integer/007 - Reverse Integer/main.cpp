//
//  main.cpp
//  007 - Reverse Integer
//
//  Created by Wu, Meng Ju on 2020/3/31.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && pop > 7)) {
                return 0;
            }
            if (res < INT_MIN/10 || (res == INT_MIN/10 && pop < -8)) {
                return 0;
            }
            res = res * 10 + pop;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
