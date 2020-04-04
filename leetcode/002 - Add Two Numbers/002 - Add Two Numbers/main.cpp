//
//  main.cpp
//  002 - Add Two Numbers
//
//  Created by Wu, Meng Ju on 2020/4/1.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0, L1=0, L2=0;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        
        while (l1 != NULL || l2 != NULL) {
            
            if (l1 != NULL && l2 != NULL) {
                L1 = l1->val;
                L2 = l2->val;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 == NULL) {
                L1 = 0;
                L2 = l2->val;
                l2 = l2->next;
            } else {
                L1 = l1->val;
                L2 = 0;
                l1 = l1->next;
            }
            head->next = new ListNode((L1 + L2 + carry) % 10);
            carry = (L1 + L2 + carry) / 10;
            head = head->next;
        }
        
        if (carry > 0) {
            head->next = new ListNode(1);
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
