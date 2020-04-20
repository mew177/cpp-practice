//
//  main.cpp
//  AVL Tree
//
//  Created by Wu, Meng Ju on 2020/4/20.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include "AVL.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    AVL tree;
    
    for (int i = 0; i < 6; i++)
        tree.insert(i);
    
    tree.traverse();
    
    return 0;
}
