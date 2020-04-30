//
//  main.cpp
//  328 - Odd Even Linked List
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
    
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* odd_tail = head;
        ListNode* even_tail =  head;
        if (even_tail->next)
            even_tail = even_tail->next;
        
        ListNode* odd_head =  odd_tail;
        ListNode* even_head = even_tail;
        
        while (even_tail && even_tail->next) {
            odd_tail->next = odd_tail->next->next;
            even_tail->next = even_tail->next->next;
            odd_tail = odd_tail->next;
            even_tail = even_tail->next;
        }
        odd_tail->next = even_head;
        return odd_head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
