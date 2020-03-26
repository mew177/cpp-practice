//
//  main.cpp
//  021 - Merge Two Sorted Lists
//
//  Created by Wu, Meng Ju on 2020/3/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(-1);
        ListNode dummy = head;
        
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    ListNode newNode = ListNode(l1->val);
                    head.next = &newNode;
                    l1 = l1->next;
                } else {
                    ListNode newNode = ListNode(l2->val);
                    head.next = &newNode;
                    l2 = l2->next;
                }
            } else if (l1 != NULL) {
                ListNode newNode = ListNode(l1->val);
                head.next = &newNode;
                l1 = l1->next;
            } else {
                ListNode newNode = ListNode(l2->val);
                head.next = &newNode;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
