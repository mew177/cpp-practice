//
//  main.cpp
//  Phonebook System
//
//  Created by Wu, Meng Ju on 2020/4/19.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    string name;
    int number;
    bool occupied;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): name(""), number(-1), occupied(false), left(NULL), right(NULL) {}
    
    void set(string name, int number) {
        this->name = name;
        this->number = number;
        this->occupied = true;
    }
    
    void info() {
        cout << name << "\t: " << number << endl;
    }
};

class Phonebook {
private:
    void _insert(TreeNode* root, string& name, int& number) {
        if (root->name < name) {
            // should save in right subtree
            if (root->right == NULL) {
                root->right = new TreeNode();
                root->right->set(name, number);
            } else {
                _insert(root->right, name, number);
            }
        } else if (root->name >= name) {
            // should save in left subtree
            if (root->left == NULL) {
                root->left = new TreeNode();
                root->left->set(name, number);
            } else {
                _insert(root->left, name, number);
            }
        }
    }
    
    TreeNode* _find(TreeNode* root, string name) {
        if (root == NULL) {
            return NULL;
        } else {
            if (root->name < name) {
                return _find(root->right, name);
            } else if (root->name > name) {
                return _find(root->left, name);
            } else {
                return root;
            }
        }
    }
    
    void _preorderTraverse(TreeNode* root) {
        if (root != NULL) {
            _preorderTraverse(root->left);
            root->info();
            _preorderTraverse(root->right);
        }
    }
    
public:
    TreeNode* root;
    int maxSize;
    
    Phonebook(): root(NULL) { }
    ~Phonebook() { }
    
    void insert(string&& name, int&& number) {
        if (root == NULL) {
            root = new TreeNode();
            root->set(name, number);
        } else {
            _insert(root, name, number);
        }
    }
    
    TreeNode* find(string name) {
        if (root == NULL) {
            return NULL;
        } else {
            return _find(root, name);
        }
    }
    
    void phonebookList() {
        _preorderTraverse(root);
    }
    
};

void info(TreeNode*&& node) {
    if (node != NULL) { node->info(); }
    else { cout << "Not found" << endl; }
}

void info(TreeNode*& node) {
    if (node != NULL) { node->info(); }
    else { cout << "Not found" << endl; }
}

int main(int argc, const char * argv[]) {
    
    Phonebook phonebook;
    phonebook.insert("Amy", 4120);
    phonebook.insert("Banny", 4123);
    phonebook.insert("Collan", 4131);
    phonebook.insert("Bonny", 4111);
    phonebook.insert("Zoe", 1211);
    phonebook.insert("Crany", 8231);
    
    info(phonebook.find("Bonny"));
    info(phonebook.find("Emily"));
    TreeNode* found = phonebook.find("Tracy");
    info(found);
    
    cout << endl;
    phonebook.phonebookList();
    
    return 0;
}
