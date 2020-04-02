//
//  main.cpp
//  013 - Roman to Integer
//
//  Created by Wu, Meng Ju on 2020/4/1.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int r2i(char c) {
        switch(c) {
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return INT_MAX;
        }
    }

public:
    int romanToInt(string s) {
        if (s == "") return 0;
        
        int ans = r2i(s[0]);
        
        for (int i = 1; i < s.size(); i++) {
            if (r2i(s[i]) > r2i(s[i-1]))
                ans -= (2 * r2i(s[i-1]));
            ans += r2i(s[i]);
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
