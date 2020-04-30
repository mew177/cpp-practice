//
//  main.cpp
//  061 - Rotate List
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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // edge case
        if (!head) return head;
        
        int leng = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            leng++;
        }
        
        k %= leng;
        if (k == 0) return head;
        
        ListNode *curr = head, *prev = NULL;
        for (int i = 0; i < leng-k; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        tail->next = head;
        prev->next = NULL;
        return curr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
