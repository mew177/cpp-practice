//
//  main.cpp
//  904 - Fruit Into Baskets
//
//  Created by Wu, Meng Ju on 2020/4/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // sliding windows
        int i = 0;
        int ans = 0;
        unordered_map<int, int> map;
        
        for (int j = 0; j < tree.size(); j++) {
            map[tree[j]]++;
            
            while (map.size() >= 3) {
                map[tree[i]] -= 1;
                if (map[tree[i]] == 0) {
                    map.erase(tree[i]);
                }
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
