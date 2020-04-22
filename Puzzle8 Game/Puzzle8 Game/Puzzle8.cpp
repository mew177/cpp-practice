//
//  Puzzle8.cpp
//  Puzzle8 Game
//
//  Created by Wu, Meng Ju on 2020/4/22.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

struct Puzzle8 {
    
    queue<vector<int>> task_queue;
    set<string> seen;
  
    vector<vector<int>> directions = {
        // four number represent the swap position in vector
        // -1 means the move is not a valid move
        {1, 3, -1, -1},
        {2, 4, 0, -1},
        {-1, 5, 1, -1},
        {4, 6, -1, 0},
        {5, 7, 3, 1},
        {-1, 8, 4, 2},
        {7, -1, -1, 3},
        {8, -1, 6, 4},
        {-1, -1, 7, 5}
    };
    
    vector<int> end_state = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
    
    Puzzle8() {
        
    }
    
    // solve
    vector<int> start_solving() {
        int steps = 0;
        vector<int> state;
        while (!task_queue.empty()) {
            state = task_queue.front();
            task_queue.pop();
            steps++;
            if (!is_game_over(state)) {
                // generate next states into queue
                next_state(state);
            } else {
                cout << "Found with iterations: " << steps << endl;
                break;
            }
        }
        return state;
    }
    
    // push a task into task_queue
    void assign_task(vector<int>& task) {
        queue<vector<int>> new_queue;
        swap(task_queue, new_queue);
        task_queue.push(task);
        seen.clear();
    }
    
    // check end state
    bool is_game_over(vector<int> & task) {
        for (int i = 0; i < task.size(); i++)
            if (end_state[i] != task[i])
                return false;
        return true;
    }
    
    int zero_index(vector<int>& task) {
        int i = 0;
        for (; i < task.size(); i++)
            if (task[i] == 0)
                break;
        return i;
    }
    
    void next_state(vector<int>& task) {
        // find the 0 in this puzzle
        vector<vector<int>> next_moves;
        vector<int> next;
        int zero_idx = zero_index(task);
        for (int move : directions[zero_idx]) {
            if (move >= 0) {
                next = vector<int>(task.begin(), task.end());
                swap(next[move], next[zero_idx]);
                if (!state_duplicate(next))
                    task_queue.push(next);
            }
        }
    }
    
    bool state_duplicate(vector<int>& task) {
        stringstream ss;
        copy(task.begin(), task.end(), ostream_iterator<int>(ss, ""));
        string s = ss.str();
        if (seen.find(s) != seen.end()) {
            return true;
        } else {
            seen.insert(s);
            return false;
            
        }
    }
    
    vector<int> mess_up(int chaos) {
        int steps = 0;
        vector<int> state;
        while (steps < chaos) {
            state = task_queue.front();
            task_queue.pop();
            steps++;
            next_state(state);
        }
        return state;
    }
};


