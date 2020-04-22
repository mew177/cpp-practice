//
//  main.cpp
//  246 - Strobogrammatic Number
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        // if there exist number 2, 3, 4, 5, 7
        // return false
        // else reading from left to right should be the same with
        // reading from right to left with rotating 180 degrees
        
        // 1? : start with 0 (No)
        
        map<char, char> rotate = {
            {'0', '0'},
            {'1', '1'},
            {'2', '#'},
            {'3', '#'},
            {'4', '#'},
            {'5', '#'},
            {'6', '9'},
            {'7', '#'},
            {'8', '8'},
            {'9', '6'},
        };
        
        for (int i = 0, j = num.size()-1; i <= j; i++, j--) {
            if (rotate[num[j]] != '#' && rotate[num[j]] == num[i]) {
                continue;
            } else {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
