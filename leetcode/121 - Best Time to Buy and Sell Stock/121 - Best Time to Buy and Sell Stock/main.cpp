//
//  main.cpp
//  121 - Best Time to Buy and Sell Stock
//
//  Created by Wu, Meng Ju on 2020/4/10.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0;
        int lowest = INT_MAX;
        
        for (int price : prices) {
            diff = max(diff, price - lowest);
            lowest = price < lowest ? price : lowest;
        }
        return diff;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
