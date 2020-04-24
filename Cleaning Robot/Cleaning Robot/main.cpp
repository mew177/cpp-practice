//
//  main.cpp
//  Cleaning Robot
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include "Robot.hpp"
#include <set>
using namespace std;

const vector<vector<int>> direction = {
    {0, -1}, {-1, 0}, {0, 1}, {1, 0}
};

void go_back(Robot& robot) {
    robot.turnLeft();
    robot.turnLeft();
    robot.move();
    robot.turnLeft();
    robot.turnLeft();
}

void backTrack(Robot& robot, pair<int, int> cell, int d, set<pair<int, int >>& seen) {
    robot.clean();
    seen.insert(cell);
    // expand to four neighbors
    for (int i = 0; i < 4; i++) {
        int new_d = (d + i) % 4;
        int new_x = cell.first + direction[new_d][0];
        int new_y = cell.second + direction[new_d][1];
        pair<int, int> new_cell = { new_x, new_y };
        if (seen.find(new_cell) == seen.end() && robot.move()) {
            backTrack(robot, new_cell, new_d, seen);
            go_back(robot);
        }
        robot.turnRight();
    }
}

void cleanRoom(Robot& robot) {
    set<pair<int, int>> seen;
    backTrack(robot, {0, 0}, 0, seen);
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> g = {
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
    };
    
    Grid grid(g);
    Robot robot(0, 0, 0, grid);
    cleanRoom(robot);
    robot.print();
    
    return 0;
}
