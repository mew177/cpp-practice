//
//  main.cpp
//  255 - Verify Preorder Sequence in Binary Search Tree
//
//  Created by Wu, Meng Ju on 2020/4/17.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int lower = INT_MIN;
        
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] < lower) {
                return false;
            }
                
            while (!s.empty() and preorder[i] > s.top()) {
                lower = s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
