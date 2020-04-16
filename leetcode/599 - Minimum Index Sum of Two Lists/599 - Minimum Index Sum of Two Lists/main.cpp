//
//  main.cpp
//  599 - Minimum Index Sum of Two Lists
//
//  Created by Wu, Meng Ju on 2020/4/15.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> record;
        for (int i = 0; i < list1.size(); i++) {
            record[list1[i]] = i;
        }
        
        int minIdx = INT_MAX;
        vector<string> list;
        for (int i = 0; i < list2.size(); i++) {
            if (record.find(list2[i]) != record.end()) {
                int i2 = i, i1 = record[list2[i]];
                if (i1 + i2 < minIdx) {
                    minIdx = i1 + i2;
                    list.clear();
                    list.push_back(list2[i]);
                } else if (i1 + i2 == minIdx) {
                    list.push_back(list2[i]);
                }
            }
        }
        return list;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
