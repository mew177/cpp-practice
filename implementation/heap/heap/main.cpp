//
//  main.cpp
//  heap
//
//  Created by Wu, Meng Ju on 2020/3/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include "heap.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Heap heap;
    
    heap.insert(3);
    heap.insert(4);
    heap.insert(8);
    heap.insert(9);
    heap.insert(7);
    heap.insert(10);
    heap.insert(9);
    heap.insert(15);
    heap.print();
    
    heap.insert(2);
    heap.print();
    
    return 0;
}
