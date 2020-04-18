//
//  main.cpp
//  225 - Implement Stack using Queues
//
//  Created by Wu, Meng Ju on 2020/4/17.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> mystack;
    int size;
    int topE;
    
    /** Initialize your data structure here. */
    MyStack(): size(0) {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        topE = x;
        size += 1;
        mystack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        size -= 1;
        if (size == 0) {
            mystack.pop();
            return topE;
        }
        
        queue<int> temp;
        int ans = topE;
        for (int i = 0; i < size; i++) {
            temp.push(mystack.front());
            mystack.pop();
        }
        mystack.pop();
        
        for (int i = 0; i < size; i++) {
            mystack.push(temp.front());
            if (i == size-1) {
                topE = temp.front();
            }
            temp.pop();
            
        }
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return topE;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
