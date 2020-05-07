//
//  main.cpp
//  708 - Insert into a Sorted Circular Linked List
//
//  Created by Wu, Meng Ju on 2020/5/7.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        // case 0:
        // head == NULL, return a single cycling node
        if (!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        bool insert = false;
        
        while (1) {
            // case 1
            // previous value <= insert value <= currenet value
            if (prev->val <= insertVal && insertVal <= curr->val) {
                insert = true;
            } else if (curr->val < prev->val) {
                // case 2
                // target is larger than max number in list
                // target is smaller than min number in list
                if (insertVal >= prev->val || curr->val >= insertVal) {
                    insert = true;
                }
            }
            
            if (insert) {
                prev->next = new Node(insertVal, curr);
                return head;
            }
            
            prev = curr;
            curr = curr->next;
            
            if (prev == head)
                // case 3
                // whole linked list contain the same number
                break;
        }
        
        prev->next = new Node(insertVal, curr);
        return head;
        
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
