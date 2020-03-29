//
//  main.cpp
//  020 - Valid Parentheses
//
//  Created by Wu, Meng Ju on 2020/3/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    
    // stack
    bool isValid(string s) {
        stack<char> stack;
        
        for (int i = 0; i < s.size(); i++) {
            if (stack.size() == 0) {
                stack.push(s[i]);
            } else {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    stack.push(s[i]);
                } else if (s[i] == ')' && stack.top() == '(') {
                    stack.pop();
                } else if (s[i] == ']' && stack.top() == '[') {
                    stack.pop();
                } else if (s[i] == '}' && stack.top() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
