//
//  Tree.cpp
//  Tree
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include "heap.hpp"
#include <iostream>
using namespace std;

void Heap::insert(int val) {
    heap.push_back(val);
    int idx = heap.size() - 1;
    
    while (heap[idx] < heap[(idx-1)/2]) {
        int tmp = heap[idx];
        heap[idx] = heap[(idx-1)/2];
        heap[(idx-1)/2] = tmp;
        idx = (idx-1)/2;
    }
};

void Heap::print() {
    for (int i = 0; i < heap.size(); i++)
        cout << heap[i] << '\t';
    cout << endl;
}
