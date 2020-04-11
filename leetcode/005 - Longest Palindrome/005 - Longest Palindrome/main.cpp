//
//  main.cpp
//  005 - Longest Palindrome
//
//  Created by Wu, Meng Ju on 2020/4/10.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    string maxExpandingLeng(string const s, int i, int j) {
        while (i >= 0 && j <= s.size()-1 && s[i] == s[j]) {
            i -= 1;
            j += 1;
        }
        
        return s.substr(i+1, j-i-1);
    }
    
public:
    string longestPalindrome(string s) {
        string longest = "";
        for (int i = 0; i < s.size(); i++) {
            string odd = maxExpandingLeng(s, i, i);
            string even = maxExpandingLeng(s, i, i+1);
            cout << odd << ',' << even << endl;
            if (odd.size() > longest.size()) {
                longest = odd;
            }
            if (even.size() > longest.size()) {
                longest = even;
            }
        }
        
        return longest;
    }
};


int main(int argc, const char * argv[]) {
    Solution sl;
    string s  ="babad";
    cout << sl.longestPalindrome(s) << endl;
    
    return 0;
}
