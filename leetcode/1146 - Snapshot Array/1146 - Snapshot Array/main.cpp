//
//  main.cpp
//  1146 - Snapshot Array
//
//  Created by Wu, Meng Ju on 2020/4/24.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> history; // pair<snap_id, value>
    int curSnap;
    
    SnapshotArray(int length)
    {
        history.resize(length, {{-1, 0}});
        curSnap = 0;
    }
    
    void set(int index, int val) {
        if (history[index].back().first < curSnap)
            history[index].push_back({curSnap, val});
        else
            history[index].back().second = val;
    }
    
    int snap() {
        return curSnap++;
    }
    
    int get(int index, int snap_id) {
        return (std::upper_bound(history[index].begin(), history[index].end(), make_pair(snap_id, INT_MAX)) - 1) ->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main(int argc, const char * argv[]) {
    
    return 0;
}
