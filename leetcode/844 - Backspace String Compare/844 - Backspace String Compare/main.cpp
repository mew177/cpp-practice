//
//  main.cpp
//  844 - Backspace String Compare
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string S_typed = "";
        string T_typed = "";
        
        for (char c : S) {
            if (c == '#') { S_typed = S_typed.substr(0, S_typed.size()-1); }
            else { S_typed += c; }
        }
        
        for (char c : T) {
            if (c == '#') { T_typed = T_typed.substr(0, T_typed.size()-1); }
            else { T_typed += c; }
        }
        
        return S_typed == T_typed;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
