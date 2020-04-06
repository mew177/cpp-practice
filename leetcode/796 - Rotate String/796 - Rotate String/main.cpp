//
//  main.cpp
//  796 - Rotate String
//
//  Created by Wu, Meng Ju on 2020/4/3.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == "" && B == "") {
            return true;
        } else if (A == "" || B == "") {
            return false;
        }
        
        map<string, bool> rotates;
        int n = A.size();
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[0]) {
                rotates[A.substr(i, n-i) + A.substr(0, i)] = true;
            }
        }
        
        if (rotates.find(B) != rotates.end()) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
