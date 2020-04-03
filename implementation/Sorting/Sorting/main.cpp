//
//  main.cpp
//  Sorting
//
//  Created by Wu, Meng Ju on 2020/3/31.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << '\t';
    }
    cout << endl;
}

/**
 insertion sort
 1. traverse every element on index:k
 2. check sequentially with its front element [0...k-1]
 3. break until num[k-1] <= num[k]
 4. k += 1
**/

void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        for (int k = i-1; k > 0; k--) {
            if (nums[k] < nums[k-1]) {
                int tmp = nums[k];
                nums[k] = nums[k-1];
                nums[k-1] = tmp;
            } else { break; }
        }
    }
}

/**
 merge sort
 */

void merge(vector<int> &nums, int l, int m, int r) {
    vector<int> merged;
    int n1 = m-l+1, n2 = r-m;
    
    int list1[n1], list2[n2];
    for (int i = 0; i < n1; i++) { list1[i] = nums[l + i]; }
    for (int j = 0; j < n2; j++) { list2[j] = nums[m + 1 + j]; }
    
    // insert element by comparing elements from two lists
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (list1[i] < list2[j]) {
            nums[k++] = list1[i++];
        } else {
            nums[k++] = list2[j++];
        }
    }
    
    // collect remain elements
    while (i < n1) { nums[k++] = list1[i++]; }
    while (j < n2) { nums[k++] = list2[j++]; }
}

void mergeSort(vector<int> &nums, int l, int r) {
    if (l < r) {
        // Same as (l+ (r-1)/2) == (l+r)/2, but avoids overflow for
        // large l and h
        int m = (l + r) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }
}

/*
 bubble sort
 1. buttom up sorting
 2. traverse list n times
 3. check every pairs, swap if needed
 
 Complexity: n = len(nums)
 
    Avg Case: O(n * n)
    Bad Case: O(n * n)
    Memory Complexity = O(1)
*/

void bubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int k = 1; k < nums.size()-1; k++) {
            if (nums[k-1] > nums[k]) {
                int tmp = nums[k-1];
                nums[k-1] = nums[k];
                nums[k] = tmp;
            }
        }
    }
}

/*
 selection sort
 1. find the smallest part
 2. swap with the first element in the unsorted part
 */

void selectionSort(vector<int>& nums) {
    int idx = 0;
    for (int i = 0; i < nums.size(); i++) {
        int s = i; // index of smallest element
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] < nums[s]) {
                s = j;
            }
        }
        int tmp = nums[s];
        nums[s] = nums[i];
        nums[i] = tmp;
        idx++;
    }
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {1, 6, 3, 8, 9, 3, 4, 7};
    selectionSort(nums);
    printVector(nums);
    
    
    
    
    return 0;
}
