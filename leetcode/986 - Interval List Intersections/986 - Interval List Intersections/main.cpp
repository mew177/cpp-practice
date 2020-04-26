//
//  main.cpp
//  986 - Interval List Intersections
//
//  Created by Wu, Meng Ju on 2020/4/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = 0, b = 0;
        vector<vector<int>> intersections;
        while (a < A.size() && b < B.size()) {
            int A_s = A[a][0], A_e = A[a][1];
            int B_s = B[b][0], B_e = B[b][1];
            
            /* //other way to find intersection
            int low = max(A_s, B_s), high = min(A_e, B_e);
            if (low <= high) intersections.push_back({low, high});
            if (A_e < B_e) a++;
            else b++;
            */
            
            // have intersection
            if (A_e <= B_e) {
                if (A_e >= B_s)
                    intersections.push_back({ max(A_s, B_s), min(A_e, B_e)} );
                a++;
            } else {
                if (B_e >= A_s)
                    intersections.push_back({ max(A_s, B_s), min(A_e, B_e)} );
                b++;
            }
        }
        return intersections;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
