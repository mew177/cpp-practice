//
//  main.cpp
//  216 - Combination Sum III
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct combination {
    int remain;
    int k;
    vector<int> comb;
    combination(int r, int K, int c) {
        remain = r;
        k = K;
        comb.push_back(c);
    }
    
    combination(int r, int K, vector<int> combs, int c) {
        remain = r;
        k = K;
        comb = combs;
        comb.push_back(c);
    }
    
    int last() {
        return comb[comb.size()-1];
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        queue<combination*> q;
        q.push(new combination(n, 0, 0));
        combination* next;
        vector<vector<int>> ans;
        
        while (!q.empty()) {
            next = q.front();
            q.pop();
            if (next->k < k) {
                for (int i = next->last()+1; i < 10; i++) {
                    q.push(new combination(next->remain-i, next->k+1, next->comb, i));
                }
            } else if (next->k == k and next->remain == 0) {
                ans.push_back(vector<int>(next->comb.begin()+1, next->comb.end()));
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
