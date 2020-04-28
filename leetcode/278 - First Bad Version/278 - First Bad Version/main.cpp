//
//  main.cpp
//  278 - First Bad Version
//
//  Created by Wu, Meng Ju on 2020/4/24.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // binary search
        // time complexity: O(logN)
        int l = 1, r = n;
        while (l < r) {
            // avoid integer overflow
            int m = (l / 2) + (r / 2) + ((r % 2) + (l % 2)) / 2;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
