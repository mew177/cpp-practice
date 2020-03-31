//
//  main.cpp
//  925 - Long Pressed Name
//
//  Created by Wu, Meng Ju on 2020/3/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct block {
    char chr;
    int cnt;
    block(): chr('#'), cnt(0) {}
    block(char c, int cnt): chr(c), cnt(cnt) {}
};

class Solution {
private:
    // group into blocks
    vector<block> _group(string str) {
        block b;
        vector<block> blocks;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != b.chr) {
                blocks.push_back(b);
                b = block(str[i], 1);
            } else {
                b.cnt += 1;
            }
        }
        return blocks;
    }

public:
    bool isLongPressedName(string name, string typed) {
        vector<block> nameBlk = _group(name);
        vector<block> typeBlk = _group(typed);
        
        if (nameBlk.size() != typeBlk.size()) { return false; }
        
        for (int i = 0; i < nameBlk.size(); i++) {
            if ((nameBlk[i].chr == typeBlk[i].chr) && (nameBlk[i].cnt <= typeBlk[i].cnt)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
