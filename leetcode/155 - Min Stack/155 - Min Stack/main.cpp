//
//  main.cpp
//  155 - Min Stack
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> minStack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if (minStack.empty()) { minStack.push_back(x); }
        else { minStack.push_back(min(x, minStack.back())); }
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
