//
//  main.cpp
//  657 - Robot Return to Origin
//
//  Created by Wu, Meng Ju on 2020/4/23.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool judgeCircle(string moves) {
        
        int horizontal = 0, vertical = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'U') { vertical++; }
            else if (moves[i] == 'D') { vertical--; }
            else if (moves[i] == 'L') { horizontal--; }
            else { horizontal++; }
        }
        return horizontal == 0 && vertical == 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
