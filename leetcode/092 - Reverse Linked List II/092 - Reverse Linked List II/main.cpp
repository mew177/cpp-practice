//
//  main.cpp
//  092 - Reverse Linked List II
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
private:
    
    ListNode* reverseLinkedList(ListNode* head) {
        if (!head || !head->next) { return head; }
        ListNode* next = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return next;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* firTail = dummy;
        ListNode* subTail = dummy;
        int count = 0;
        
        while (count < m-1) {
            firTail = firTail->next;
            subTail = subTail->next;
            count++;
        }
        
        while (count < n) {
            subTail = subTail->next;
            count++;
        }
        
        ListNode* subHead = firTail->next;
        ListNode* secHead = subTail->next;
        
        // unlinked sub-linked list with main linkedlist
        firTail->next = NULL;
        subTail->next = NULL;
        // reverse sub-linkedlist
        reverseLinkedList(subHead);
        // relink sub-linkedlist with main linkedlist
        firTail->next = subTail;
        subHead->next = secHead;
        return dummy->next;
        
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
