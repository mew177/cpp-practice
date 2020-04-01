//
//  main.cpp
//  759 - Employee Free Time
//
//  Created by Wu, Meng Ju on 2020/3/31.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

struct cmp {
    
    bool operator()(const Interval& it1, const Interval& it2) {
        if (it1.start < it2.start) {
            return false;
        } else if (it1.start == it2.start) {
            if (it1.end > it2.end) {
                return false;
            } else {
                return true;
            }
        } else {
            return true;
        }
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<Interval, vector<Interval>, cmp> queue;
        for (vector<Interval> person: schedule) {
            for (Interval interval: person) {
                queue.push(interval);
            }
        }
        
        vector<Interval> freeTime;
        int start=0, end=0;
        while (!queue.empty()) {
            if (queue.top().start == start) {
                end = max(queue.top().end, end);
            } else {
                if (queue.top().start <= end) {
                    end = max(queue.top().end, end);
                } else {
                    freeTime.push_back(*(new Interval(end, queue.top().start)));
                    start = queue.top().start;
                    end = queue.top().end;
                }
            }
            queue.pop();
        }
        
        if (freeTime[0].start == 0) {
            freeTime.erase(freeTime.begin());
        }
        return freeTime;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
