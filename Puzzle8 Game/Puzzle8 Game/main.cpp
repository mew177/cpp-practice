//
//  main.cpp
//  Puzzle8 Game
//
//  Created by Wu, Meng Ju on 2020/4/22.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Puzzle8.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> task1 = {1,2,3,4,6,0,7,5,8};
    vector<int> task2 = {2,3,0,1,5,6,4,7,8};
    vector<int> task3 = {4,1,2,7,6,3,0,5,8};
    vector<int> task4 = {4,1,2,7,6,3,5,8,0};
    vector<int> task5 = {5,3,0,4,7,6,2,1,8};
    vector<int> task6 = {1,2,3,4,5,6,7,8,0};
    
    // solve task 5
    Puzzle8 helper;
    helper.assign_task(task5);
    helper.start_solving();
    
    // 30000 is the chaosity
    helper.assign_task(task6);
    task6 = helper.mess_up(30000);
    
    cout << task6[0] << " " << task6[1] << " " << task6[2] << endl;
    cout << task6[3] << " " << task6[4] << " " << task6[5] << endl;
    cout << task6[6] << " " << task6[7] << " " << task6[8] << endl;
    
    helper.assign_task(task6);
    helper.start_solving();
    
    return 0;
}
