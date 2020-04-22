//
//  main.cpp
//  232 - Implement Queue using Stacks
//
//  Created by Wu, Meng Ju on 2020/4/17.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> myqueue;
    int size;
    int front;
    MyQueue(): size(0) {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (size == 0) {
            front = x;
        }
        size += 1;
        myqueue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        size -= 1;
        
        if (size == 0) {
            myqueue.pop();
            return front;
        }
        
        stack<int> temp;
        int ans = front;
        for (int i = 0; i < size; i++) {
            temp.push(myqueue.top());
            myqueue.pop();
        }
        
        front = temp.top();
        for (int i = 0; i < size; i++) {
            myqueue.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (size == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
