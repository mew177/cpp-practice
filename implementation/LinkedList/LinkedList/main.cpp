//
//  main.cpp
//  LinkedList
//
//  Created by Wu, Meng Ju on 2020/4/29.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val): value(val), next(NULL) {}
};

class LinkedList {
private:
    
public:
    ListNode* head;
    LinkedList(): head(NULL) {}
    
    void insert(int val) {
        if (!head)
            head = new ListNode(val);
        else {
            ListNode* node = head;
            while (node->next)
                node = node->next;
            node->next = new ListNode(val);
        }
    }
    
    void print() {
        ListNode* node = head;
        while (node) {
            cout << node->value << " -> ";
            node = node->next;
        }
        cout << "NULL" << endl << endl;
    }
};

/* reverse a linked list */
// a iterative fashion to reverse a linked list
ListNode* _iterativeReverseLinkedList(ListNode* head) {
    ListNode* reversed_head = NULL;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* next = curr->next;
        curr->next = reversed_head;
        reversed_head = curr;
        curr = next;
    }
    return reversed_head;
}

ListNode* iterativeReverseLinkedList(ListNode* head) {
    return _iterativeReverseLinkedList(head);
}

ListNode* _recursiveReverseLinkedList(ListNode* head) {
    // if node is NULL or it is the only node in linkedlist
    if (!head || !head->next) { return head; }
    // get the new head node
    ListNode* new_head = _recursiveReverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

// a recursive fashion to reverse a linked list
ListNode* recursiveReverseLinkedList(ListNode* head) {
    return _recursiveReverseLinkedList(head);
}

/* reverse a linked list with noted index */

ListNode* recursiveReversedWithIndexRange(ListNode* head) {
    
    return NULL;
}

ListNode* _recursiveReversedWithIndexRange(ListNode* head, int m, int n) {
    
    return NULL;
}

ListNode* iterativeReversedWithIndexRange(ListNode* head, int m, int n) {
    // there are three cases will happen
    // 1. [1, {2, 3, 4, 5}, 6] reverse range where (m > 1 and n < N)
    // 2. [{1, 2, 3, 4, 5}, 6] reverse range start from 1
    // 3. [{1, 2, 3, 4, 5, 6}] reverse range end with n == N
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    // this with point at the tail of first section
    ListNode* front_tail = dummy;
    // this with point at the tail of second section
    ListNode* sub_tail = dummy;
    int count = 0;
    // place front_tail at correct position
    while (count < m-1 && front_tail) {
        front_tail = front_tail->next;
        sub_tail = sub_tail->next;
        count++;
    }
    // place sub_tail at correct position
    while (count < n && sub_tail) {
        sub_tail = sub_tail->next;
        count++;
    }
    // this with point at the head of second section
    ListNode* sub_head = front_tail->next;
    // this with point at the head of third section
    ListNode* third_head = sub_tail->next;
    
    // reverse linkedlist between sub_head ~ sub_tail
    front_tail->next = NULL;
    sub_tail->next = NULL;
    iterativeReverseLinkedList(sub_head);
    // this time originally sub_head will be sub_tail
    // originally sub_tail will be sub_head
    // reconnect three part
    front_tail->next = sub_tail;
    sub_head->next = third_head;
    return dummy->next;
}

/* reverse first K nodes */

ListNode* reverseFirstKnodes(ListNode* head, int k) {
    ListNode* curr = head;
    ListNode* reversed_head = NULL;
    while (k) {
        ListNode* next = curr->next;
        curr->next = reversed_head;
        reversed_head = curr;
        curr = next;
        k--;
    }
    
    return reversed_head;
}

ListNode* recursiveReverseEveryKnodes(ListNode* head, int K) {
    int k = 0;
    // this pointed at the kth next node
    ListNode* curr = head;
    
    while (k < K && curr) {
        curr = curr->next;
        k++;
    }
    
    // if remaining nodes actually have k
    // reverse K nodes after curr
    if (k == K) {
        ListNode* reversed_head = reverseFirstKnodes(head, K);
        head->next = recursiveReverseEveryKnodes(curr, K);
        return reversed_head;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    LinkedList list;
    for (int i = 1; i < 10; i++) {
        list.insert(i);
    }
    list.print();
    
    cout << "Printed by recursiveReverseLinkedList()" << endl;
    list.head = recursiveReverseLinkedList(list.head);
    list.print();
    
    cout << "Printed by iterativeReverseLinkedList()" << endl;
    list.head = iterativeReverseLinkedList(list.head);
    list.print();
    
    cout << "Printed by iterativeReversedWithIndexRange(3, 6)" << endl;
    list.head = iterativeReversedWithIndexRange(list.head, 3, 6);
    list.print();
    
    cout << "Printed by iterativeReversedWithIndexRange(1, 2)" << endl;
    list.head = iterativeReversedWithIndexRange(list.head, 1, 2);
    list.print();
    
    cout << "Printed by iterativeReversedWithIndexRange(7, 9)" << endl;
    list.head = iterativeReversedWithIndexRange(list.head, 7, 9);
    list.print();
    
    cout << "Printed by recursiveReverseEveryKnodes(2)" << endl;
    list.head = recursiveReverseEveryKnodes(list.head, 2);
    list.print();
    
    return 0;
}
