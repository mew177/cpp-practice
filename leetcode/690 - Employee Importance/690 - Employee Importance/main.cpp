//
//  main.cpp
//  690 - Employee Importance
//
//  Created by Wu, Meng Ju on 2020/4/17.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    map<int, vector<int>> directOrds;
    map<int, int> values;
    
    int getImportance(vector<Employee*> employees, int id) {
        for (Employee *e : employees) {
            values[e->id] = e->importance;
            for (int id : e->subordinates) {
                directOrds[e->id].push_back(id);
            }
        }
        
        queue<int> q;
        q.push(id);
        int total = 0;;
        
        while (!q.empty()) {
            id = q.front();
            q.pop();
            total += values[id];
            for (int ord : directOrds[id]) {
                q.push(ord);
            }
        }
        return total;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
