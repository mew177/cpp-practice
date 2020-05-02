//
//  main.cpp
//  1055 - Shortest Way to Form String
//
//  Created by Wu, Meng Ju on 2020/5/2.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        // <character, [indexes]>
        map<char, vector<int>> indexes;
        for (int i = 0; i < source.size(); i++)
            indexes[source[i]].push_back(i);
        
        int prev = -1;
        int count = 0;
        for (int idx = 0; idx < target.size(); idx++) {
            if (indexes.find(target[idx]) != indexes.end()) {
                // found the character in indexes
                bool foundLarger = false;
                // found a fitting index which is larger than the previous one
                for (int i : indexes[target[idx]]) {
                    if (i > prev) {
                        prev = i;
                        foundLarger = true;
                        break;
                    }
                }
                if (!foundLarger) {
                    count++;
                    prev = indexes[target[idx]][0];
                }
            } else {
                // not found a character
                return -1;
            }
        }
        return count+1;
    }
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
