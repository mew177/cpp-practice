//
//  main.cpp
//  004 - Median of Two Sorted Arrays
//
//  Created by Wu, Meng Ju on 2020/3/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    // merge two array and find median
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArr;
        int i=0, j=0;
        
        while (i < nums1.size() || j < nums2.size()) {
            if (i >= nums1.size()) {
                mergedArr.push_back(nums2[j++]);
            } else if (j >= nums2.size()) {
                mergedArr.push_back(nums1[i++]);
            } else if (nums1[i] < nums2[j]) {
                mergedArr.push_back(nums1[i++]);
            } else{
                mergedArr.push_back(nums2[j++]);
            }
        }
        
        int n = mergedArr.size();
        if (mergedArr.size() % 2 == 0) {
            return double(mergedArr[n/2] + mergedArr[(n/2)-1]) / 2;
        } else {
            return double(mergedArr[n/2]);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
