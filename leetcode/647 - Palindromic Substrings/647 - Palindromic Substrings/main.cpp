//
//  main.cpp
//  647 - Palindromic Substrings
//
//  Created by Wu, Meng Ju on 2020/5/2.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    
    int expand(int i, int j, string s) {
        int candidates = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            candidates += 1;
            i -= 1;
            j += 1;
        }
        return candidates;
    }
    
public:
    int countSubstrings(string s) {
        int candidates = 0;
        
        for (int i = 0; i < s.size(); i++) {
            candidates += expand(i, i, s);
            candidates += expand(i, i+1, s);
        }
        return candidates;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
