//
//  main.cpp
//  346 - Moving Average from Data Stream
//
//  Created by Wu, Meng Ju on 2020/4/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    int sum;
    int size;
    queue<int> Q;
    
    MovingAverage(int size): size(size), sum(0) {
        
    }
    
    double next(int val) {
        if (Q.size() >= size) {
            sum -= Q.front();
            sum += val;
            Q.pop();
            Q.push(val);
        } else {
            sum += val;
            Q.push(val);
        }
        return double(sum) / Q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
