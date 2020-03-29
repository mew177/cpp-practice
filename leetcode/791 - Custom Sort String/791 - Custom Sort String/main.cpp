//
//  main.cpp
//  791 - Custom Sort String
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> charMap;
        
        // collect character from T
        for (int i = 0; i < T.size(); i++) {
            if (charMap.find(T[i]) != charMap.end()) {
                charMap[T[i]] += 1;
            } else {
                charMap[T[i]] = 1;
            }
        }
        
        // reorder by S
        string newSorted = "";
        for (int i = 0; i < S.size(); i++) {
            for (int time = 0; time < charMap[S[i]]; time++) {
                newSorted += S[i];
            }
            charMap.erase(S[i]);
        }
        
        // remain character in charBag
        for (map<char, int>::iterator it = charMap.begin(); it != charMap.end(); ++it) {
            for (int i = 0; i < it->second; i++) {
                newSorted += (it->first);
            }
        }
        
        return newSorted;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
