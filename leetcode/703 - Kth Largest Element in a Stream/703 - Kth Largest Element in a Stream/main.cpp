//
//  main.cpp
//  703 - Kth Largest Element in a Stream
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> queue;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int i = 0;
        while (i < nums.size()) {
            if (i < k) {
                queue.push(nums[i]);
            } else {
                if (nums[i] > queue.top()) {
                    queue.pop();
                    queue.push(nums[i]);
                }
            }
            i++;
        }
    }
    
    int add(int val) {
        if (queue.size() < k) {
            queue.push(val);
        } else if (val > queue.top()) {
            queue.pop();
            queue.push(val);
        }
        return queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, const char * argv[]) {
    
    return 0;
}
