//
//  main.cpp
//  237 - Delete Node in a Linked List
//
//  Created by Wu, Meng Ju on 2020/4/12.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while (node != NULL) {
            if (node->next != NULL) {
                node->val = node->next->val;
                prev = node;
            } else {
                prev->next = NULL;
            }
            node = node->next;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
