//
//  main.cpp
//  206 - Reverse Linked List
//
//  Created by Wu, Meng Ju on 2020/4/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    
    ListNode* recursive(ListNode* head) {
        // if input is NULL or head is the only node in linkedlist
        if(!head || !head->next) { return head; }
        ListNode* reversed_head = recursive(head->next);
        // (Xn) -> (Xn+1) -> X(n)
        // head     next     head
        head->next->next = head;
        // (Xn+1) -> X(n) -> NULL
        //  next    head
        head->next = NULL;
        return reversed_head;
    }
    
    ListNode* iterative(ListNode* head) {
        // this record the reversed head in every level
        ListNode* reversedHead = NULL;
        // this record the on processing head
        ListNode* curr = head;
        while (curr) {
            // this record the node which is going to be processed next
            ListNode* next = curr->next;
            curr->next = reversedHead;
            reversedHead = curr;
            curr = next;
        }
        return reversedHead;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        return iterative(head);
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
