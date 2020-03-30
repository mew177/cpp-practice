//
//  heap.hpp
//  heap
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp
#include <vector>
using namespace std;

class Heap {
public:
    vector<int> heap;
    
    Heap() {};
    ~Heap() {};
    
    void insert(int);
    void find(int);
    void parent();
    void left();
    void right();
    void print();
    
    
};

#endif /* heap_hpp */
