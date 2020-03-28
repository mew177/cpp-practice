//
//  main.cpp
//  023 - Merge k Sorted Lists
//
//  Created by Wu, Meng Ju on 2020/3/27.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() {}
     ListNode(int x) : val(x), next(NULL) {}
 };

struct cmp {
  bool operator()(ListNode *n1, ListNode *n2) {
      return n1->val > n2->val;
  }
};

class Solution {
    
public:
    
    // prority queue based
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        ListNode* head = new ListNode();
        ListNode* ans = head;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> queue;
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                queue.push(lists[i]);
            }
        }
        
        while (!queue.empty()) {
            ListNode* tmp = queue.top();
            head->next = tmp;
            queue.pop();
            if (tmp->next != NULL) {
                queue.push(tmp->next);
            }
            head = head->next;
        }
        return ans->next;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
