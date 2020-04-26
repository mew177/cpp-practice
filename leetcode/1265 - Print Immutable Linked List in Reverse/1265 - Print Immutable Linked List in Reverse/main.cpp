//
//  main.cpp
//  1265 - Print Immutable Linked List in Reverse
//
//  Created by Wu, Meng Ju on 2020/4/21.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

class ImmutableListNode {
public:
    void printValue(); // print the value of the node.
    ImmutableListNode* getNext(); // return the next node.
};

int main(int argc, const char * argv[]) {
    
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head != NULL) {
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
    return 0;
}
