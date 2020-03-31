//
//  main.cpp
//  088 - Merge Sorted Array
//
//  Created by Wu, Meng Ju on 2020/3/28.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr = m+n-1;
        int i = m-1, j = n-1;
        
        while (ptr >= 0) {
            if (i < 0) {
                nums1[ptr--] = nums2[j--];
            } else if (j < 0) {
                nums1[ptr--] = nums1[i--];
            } else {
                if (nums1[i] > nums2[j]) {
                    nums1[ptr--] = nums1[i--];
                } else {
                    nums1[ptr--] = nums2[j--];
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
