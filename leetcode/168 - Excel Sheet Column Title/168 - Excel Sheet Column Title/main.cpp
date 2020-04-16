//
//  main.cpp
//  168 - Excel Sheet Column Title
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string index = "";
        int mod=0;
        while (n > 0) {
            n -= 1;
            mod = n % 26;
            n = n / 26;
            index = char(mod + 65) + index;
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
