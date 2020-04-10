//
//  main.cpp
//  Trie
//
//  Created by Wu, Meng Ju on 2020/4/6.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Node {
    char chr;
    map<char, Node*> children;
    Node(char chr): chr(chr) {}
    
    Node* exist(char child) {
        if (children.find(child) != children.end()) {
            return children[child];
        } else {
            return NULL;
        }
    }
    
    Node* createChild(char child) {
        children[child] = new Node(child);
        return children[child];
    }
};

class Trie {
private:
    
    bool _finds(string word, Node* root) {
        if (word != "") {
            if (word[0] != '.') {
                Node* child = root->exist(word[0]);
                if (child != NULL) {
                    return _finds(word.erase(0, 1), child);
                } else { return false; }
            } else {
                for (map<char, Node*>::iterator it=root->children.begin(); it != root->children.end(); ++it) {
                    word.erase(0, 1);
                    if (_finds(word, it->second)) {
                        return true;
                    }
                }
                return false;
            }
            
        } else {
            Node* child = root->exist('#');
            return (child != NULL);
        }
    }
    
public:
    Node* root;
    Trie() {
        root = new Node('*');
    }
    
    void insert(string str) {
        Node* node = root;
        for (int i = 0; i < str.size(); i++) {
            Node* child = node->exist(str[i]);
            if (child != NULL) {
                node = child;
            } else {
                node = node->createChild(str[i]);
            }
        }
        node->createChild('#');
    }
    
    void traverse(Node *root) {
        if (root != NULL) {
            if (root->chr == '#') { cout << root->chr << endl; }
            else { cout << root->chr; } ;
            for (map<char, Node*>::iterator it=root->children.begin(); it != root->children.end(); ++it) {
                traverse(it->second);
            }
        }
    }
    
    bool find(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            Node* child = node->exist(word[i]);
            if (child != NULL) {
                node = child;
            } else {
                return false;
            }
        }
        if (node->exist('#') != NULL) {
            return true;
        } else {
            return false;
        }
    }
    
    bool finds(string word) {
        return _finds(word, root);
    }
    
    
};

int main(int argc, const char * argv[]) {
    
    Trie trie;
    
    string word1 = "apple";
    string word2 = "application";
    string word3 = "banana";
    string word4 = "ban";
    trie.insert(word1);
    trie.insert(word2);
    trie.insert(word3);
    trie.insert(word4);
    
    trie.traverse(trie.root);
    
    cout << trie.finds("application") << endl;
    cout << trie.finds("apple") << endl;
    cout << trie.finds("app") << endl;
    cout << trie.finds("banana") << endl;
    cout << trie.finds("ban") << endl;
    
    return 0;
}
