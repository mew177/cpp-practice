//
//  Robot.cpp
//  Cleaning Robot
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include "Robot.hpp"
    
Robot::Robot():
direction({{0, -1}, {-1, 0}, {0, 1}, {1, 0}}),
x(0), y(0), facing(1)
{
    
}

Robot::Robot(int x, int y, int f, Grid& grid):
direction({{0, 1}, {1, 0}, {0, -1}, {-1, 0}}),
x(x), y(y), facing(f), grid(grid)
{
    
}

Robot::~Robot() {
    
}
    
/* move forward if possible and return true */
/* if encounter an obstable, stay and return false */
bool Robot::move() {
    return _move();
};

/* move in a given grid */
bool Robot::_move() {
    int new_x = x + direction[facing].first;
    int new_y = y + direction[facing].second;
    if (grid.stuck(new_x, new_y)) {
        // encounter a obstacle
        // reach grid edges
        return false;
    }
    // move forward
    x = new_x;
    y = new_y;
    return true;
};

void Robot::turnRight() {
    facing = (facing + 1) % 4;
};

void Robot::turnLeft() {
    facing = (facing + 3) % 4;
};

void Robot::clean() {
    _clean();
}

void Robot::_clean() {
    grid.clean(x, y);
};


void Robot::print() {
    grid.print();
};


void Robot::position() {
    cout << x << ',' << y << ':' << facing << endl;
}



