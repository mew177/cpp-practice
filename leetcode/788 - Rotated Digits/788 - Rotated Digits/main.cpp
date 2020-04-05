//
//  main.cpp
//  788 - Rotated Digits
//
//  Created by Wu, Meng Ju on 2020/4/2.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for(int n = 1; n < N+1; n++) {
            bool rotateable = false;
            int num = n;
            while (num > 0) {
                int mod = num % 10;
                if (mod == 3 || mod == 4 || mod == 7) {
                    rotateable = false;
                    break;
                } else if (mod == 2 || mod == 5 || mod == 6 || mod == 9) {
                    rotateable = true;
                }
                num = num / 10;
            }
            if (rotateable) { cnt++; }
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
