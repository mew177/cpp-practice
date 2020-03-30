//
//  main.cpp
//  021 - Merge Two Sorted List
//
//  Created by Wu, Meng Ju on 2020/3/26.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x): val(x), next(NULL) {}
};

class solution {
public:
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoList(l1, l2->next);
            return l2;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
