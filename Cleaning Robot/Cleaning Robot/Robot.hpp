//
//  Robot.hpp
//  Cleaning Robot
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#ifndef Robot_hpp
#define Robot_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Grid.cpp"
using namespace std;

class Robot {
private:
    int x;
    int y;
    int facing;
    vector<pair<int, int>> direction;
    Grid grid;
    
    bool _move();
    void _clean();
    
public:
    
    Robot();
    Robot(int, int, int, Grid&);
    ~Robot();
    bool move();
    void turnRight();
    void turnLeft();
    void clean();
    void print();
    
    void position();
};

#endif /* Robot_hpp */
