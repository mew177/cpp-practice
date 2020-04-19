//
//  main.cpp
//  171 - Excel Sheet Column Number
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            num = num * 26 + (int(s[i]) - 64);
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
