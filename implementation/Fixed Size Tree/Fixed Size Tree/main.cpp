//
//  main.cpp
//  Fixed Size Tree
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include "Tree.cpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    Tree tree(10);
    
    TreeNode* node;
    for (int i = 1; i < 9; i++) {
        node = tree.get();
        if (node != NULL) {
            node->set(to_string(1111*i), to_string(i));
        }
    }
    
    tree.release(8);
    tree.release(1);
    tree.traverse();
    
    tree.check(5);
    tree.check(8);
    tree.check(9);
    tree.check(12);
    
    return 0;
}
