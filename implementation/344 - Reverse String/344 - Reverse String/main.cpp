//
//  main.cpp
//  344 - Reverse String
//
//  Created by Wu, Meng Ju on 2020/4/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // solution 4
        // two pointers
        int l = 0, r = s.size()-1;
        while (l < r)
            swap(s[l++], s[r--]);
        return;
        
        // solution 3
        // for loop
        for (int i = 0; i < s.size()/2; i++)
            swap(s[i], s[s.size()-i-1]);
        return;
        
        // solution 2
        // vector reverse
        reverse(s.begin(), s.end());
        return;
        
        // solution 1
        stack<char> stk;
        for (char c : s)
            stk.push(c);
        
        int i = 0;
        while (!stk.empty()) {
            s[i++] = stk.top();
            stk.pop();
        }
        return;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
