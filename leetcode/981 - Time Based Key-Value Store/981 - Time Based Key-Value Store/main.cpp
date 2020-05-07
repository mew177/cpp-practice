//
//  main.cpp
//  981 - Time Based Key-Value Store
//
//  Created by Wu, Meng Ju on 2020/5/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class TimeMap {
public:
    /** Initialize your data structure here. */
    
    unordered_map<string, map<int, string>> records;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        records[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (records.find(key) == records.end())
            return "";
        
        for (auto it=records[key].rbegin(); it != records[key].rend(); it++) {
            if ((it->first) <= timestamp) {
                return (it->second);
            }
        }
        return "";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
