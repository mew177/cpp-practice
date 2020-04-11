//
//  main.cpp
//  009 - Palindrome Number
//
//  Created by Wu, Meng Ju on 2020/4/11.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        stack<int> q;
        int num = x;
        while (num > 0) {
            q.push(num % 10);
            num = num / 10;
        }
        
        while (x > 0) {
            if (x % 10 == q.top()) {
                q.pop();
                x = x / 10;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
