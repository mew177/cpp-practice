//
//  main.cpp
//  345 - Reverse Vowels of a String
//
//  Created by Wu, Meng Ju on 2020/4/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> map = {
            {'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1},
            {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}
        };
        
        // left pointer and right pointer
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (map[s[i]] != 1) {
                i += 1;
            } else if (map[s[j]] != 1) {
                j -= 1;
            } else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
