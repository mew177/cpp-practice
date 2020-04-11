//
//  main.cpp
//  1137 - N-th Tribonacci Number
//
//  Created by Wu, Meng Ju on 2020/4/10.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int tribonacci(int n) {
        int numbers[n+1];
        
        if (n >= 0) { numbers[0] = 0; }
        if (n >= 1) { numbers[1] = 1; }
        if (n >= 2) { numbers[2] = 1; }
        for (int i = 3; i < n+1; i++) {
            numbers[i] = numbers[i-1] + numbers[i-2] + numbers[i-3];
        }
        
        return numbers[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
