//
//  main.cpp
//  729 - My Calendar I
//
//  Created by Wu, Meng Ju on 2020/4/16.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Interval {
public:
    int start;
    int end;
    
    Interval(int s, int e): start(s), end(e) {}
    bool overlapped(Interval interval) {
        if (interval.end <= start or interval.start >= end) {
            return false;
        } else {
            return true;
        }
    }
};

class MyCalendar {
public:
    vector<Interval> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        Interval candidate{start, end};
        for (Interval interval : intervals) {
            if (candidate.overlapped(interval)) {
                return false;
            }
        }
        intervals.push_back(candidate);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main(int argc, const char * argv[]) {
    
    return 0;
}
