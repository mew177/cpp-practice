//
//  main.cpp
//  725 - Split Linked List in Parts
//
//  Created by Wu, Meng Ju on 2020/4/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
private:
    
    ListNode* next_head(ListNode* root, int k) {
        if (!root) return root;
        
        ListNode* head = root;
        for (int i = 0; i < k-1; i++)
            head = head->next;
        ListNode* next_head = head->next;
        head->next = NULL;
        return next_head;
    }
    
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        int length = 0;
        ListNode* node = root;
        while (node) {
            length += 1;
            node = node->next;
        }
        
        int mod =  length % k;
        int div = length / k;
        
        vector<ListNode*> heads;
        ListNode* curr = root;
        
        for (int round = 0; round < k; round++) {
            heads.push_back(curr);
            int size = div;
            size += mod > 0 ? 1 : 0;
            mod--;
            curr = next_head(curr, size);
        }
        
        return heads;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
