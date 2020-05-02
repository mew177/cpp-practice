//
//  main.cpp
//  1089 - Duplicate Zeros
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == 0) {
                q.push(arr[i]);
            }
            
            if (!q.empty()) {
                q.push(arr[i]);
                arr[i] = q.front();
                q.pop();
            }
            i++;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
