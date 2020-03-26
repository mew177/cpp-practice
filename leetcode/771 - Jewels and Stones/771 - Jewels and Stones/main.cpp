//
//  main.cpp
//  771 - Jewels and Stones
//
//  Created by Wu, Meng Ju on 2020/3/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, bool> myJwl;
        for (int i = 0; i < J.size(); i++) {
            myJwl[J[i]] = true;
        }
        
        int count = 0;
        for (int i = 0; i < S.size(); i++) {
            if (myJwl.find(S[i]) != myJwl.end()) { count ++; }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
