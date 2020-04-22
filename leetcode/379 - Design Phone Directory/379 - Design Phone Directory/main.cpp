//
//  main.cpp
//  379 - Design Phone Directory
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    vector<bool> phonebook;
    int maxNumbers;
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        for (int i = 0; i < maxNumbers; i++) {
            phonebook.push_back(false);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for (int i = 0; i < maxNumbers; i++) {
            if (!phonebook[i]) {
                phonebook[i] = true;
                return i;
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !phonebook[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        phonebook[number] = false;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
