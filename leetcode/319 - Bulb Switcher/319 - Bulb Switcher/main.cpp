//
//  main.cpp
//  319 - Bulb Switcher
//
//  Created by Wu, Meng Ju on 2020/4/21.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int lights = 0;
        lights = sqrt(n);
        return lights;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
