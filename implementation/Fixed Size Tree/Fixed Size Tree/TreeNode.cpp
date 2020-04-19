//
//  TreeNode.cpp
//  Fixed Size Tree
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
    bool occupied;
    int index;
    string name;
    string number;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int i): index(i) {
        occupied = false;
        name = "";
        number = "";
        left = NULL;
        right = NULL;
    }
    
    ~TreeNode() {}
    
    void set(string name, string number) {
        this->name = name;
        this->number = number;
        this->occupied = true;
    }
    
    bool isOccupied() {
        return occupied;
    }
    
    void release() {
        occupied = false;
    }
    
    void info() {
        cout << index << ": " << name << ": " << number << "[" << occupied << "]" << endl;
    }
};
