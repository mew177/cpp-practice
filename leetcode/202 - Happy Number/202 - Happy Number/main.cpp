//
//  main.cpp
//  202 - Happy Number
//
//  Created by Wu, Meng Ju on 2020/3/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> checked;
        
        while (true) {
            int num = 0;
            while (n > 0) {
                num += (n % 10) * (n % 10);
                n = n / 10;
            }
            
            if (checked.find(num) != checked.end()) { return false; }
            if (num == 1) { return true; }
            n = num;
            checked.insert(num);
        }
        
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
