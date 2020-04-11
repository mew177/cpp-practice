//
//  main.cpp
//  208 - Implement Trie (Prefix Tree)
//
//  Created by Wu, Meng Ju on 2020/4/11.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    char chr;
    map<char, Node*> children;
    
    Node(char c): chr(c) {}
    
    Node* exist(char c) {
        if (children.find(c) != children.end()) {
            return children[c];
        } else {
            return NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root = new Node('#');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            Node* next = node->exist(word[i]);
            if (next != NULL) {
                node = next;
            } else {
                node->children[word[i]] = new Node(word[i]);
                node = node->children[word[i]];
            }
        }
        node->children['*'] = new Node('*');
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            Node* next = node->exist(word[i]);
            if (next == NULL) {
                return false;
            } else {
                node = next;
            }
        }
        if (node->exist('*') != NULL) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            Node* next = node->exist(prefix[i]);
            if (next == NULL) {
                return false;
            } else {
                node = next;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
