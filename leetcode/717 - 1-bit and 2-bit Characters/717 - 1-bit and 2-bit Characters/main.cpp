//
//  main.cpp
//  717 - 1-bit and 2-bit Characters
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int i = 0;
        while (i < bits.size()-1) {
            if (bits[i] == 0) {
                // if bit[i] = 0, it must be one bit character
                i += 1;
            } else {
                // if bit[i] = 1, it must be two bits character
                i += 2;
            }
        }
        return i == bits.size()-1;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
