//
//  main.cpp
//  003 - Longest Substring Without Repeating Characters
//
//  Created by Wu, Meng Ju on 2020/3/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
private:
    
public:
    // sliding window based
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, bool> table;
        int ans = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < n) {
            if (table.find(s[j]) == table.end()) {
                table[s[j++]] = true;
                ans = max(ans, j - i);
            } else {
                table.erase(s[i++]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
