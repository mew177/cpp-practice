//
//  main.cpp
//  1021 - Remove Outermost Parentheses
//
//  Created by Wu, Meng Ju on 2020/4/17.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string rebuild = "";
        int left=0, right=0, prev=0;
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                left += 1;
            } else {
                right += 1;
            }
            
            if (left == right) {
                rebuild += S.substr(prev+1, i-prev-1);
                prev = i+1;
                left = 0;
                right = 0;
            }
        }
        return rebuild;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
