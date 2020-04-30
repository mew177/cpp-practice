//
//  main.cpp
//  Moore's Voting Algorithm
//
//  Created by Wu, Meng Ju on 2020/4/30.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void twoForLoop(vector<int>& numbers) {
    int maxCount = 0, maxNumber = 0;
    for (int i = 0; i < numbers.size(); i++) {
        int count = 0;
        for (int j = i; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j])
                count++;
        }
        
        if (count > maxCount) {
            maxCount = count;
            maxNumber = numbers[i];
        }
        
        if (maxCount > numbers.size() / 2) {
            // if there is one number has more than half numbers of the length
            // this is definitely the majority
            cout << "Majority number is " << maxNumber << endl;
            return;
        }
    }
    cout << "Mojority not found" << endl;
}

void onePassScanWithMap(vector<int>& numbers) {
    // <number, count>
    unordered_map<int, int> counter;
    for (int num : numbers)
        counter[num]++;
    
    int length = numbers.size();
    for (auto [number, count] : counter) {
        if (count > length/2) {
            cout << "Majority number is " << number << endl;
            return;
        }
    }
    cout << "Mojority not found" << endl;
}

void mooresVoting(vector<int>& numbers) {
    int ptr = 0;
    int count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (count == 0) {
            ptr = i;
            count = 1;
        } else {
            if (numbers[i] == numbers[ptr])
                count++;
            else
                count--;
        }
    }
    cout << "Majority number is " << numbers[ptr] << endl;
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int count;
    TreeNode(int v): val(v), left(NULL), right(NULL), count(1) {}
    ~TreeNode();
};

struct BST {
    TreeNode* root;
    BST(): root(NULL) {}
    ~BST() {}
    
    int _insert(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node = root;
        
        while(!q.empty()) {
            node = q.front();
            q.pop();
            
            if (node) {
                if (node->val < val) {
                    if (node->right) {
                        q.push(node->right);
                    } else {
                        node->right = new TreeNode(val);
                        node = node->right;
                    }
                } else if (node->val > val) {
                    if (node->left) {
                        q.push(node->left);
                    } else {
                        node->left = new TreeNode(val);
                        node = node->left;
                    }
                } else {
                    node->count++;
                }
            }
        }
        
        return node->count;
    }
    
    int insert(int val) {
        int count = 0;
        if (!root) {
            root = new TreeNode(val);
            count = root->count;
        } else {
            count = _insert(root, val);
        }
        
        return count;
    }
};

void countWithBST(vector<int>& numbers) {
    BST bst;
    int leng = numbers.size();
    for (int num : numbers) {
        int count = bst.insert(num);
        if (count > leng / 2) {
            cout << "Majority number is " << num  << endl;
            return;
        }
    }
    cout << "Mojority not found" << endl;
}

int main(int argc, const char * argv[]) {
    /*  Given a list of numbers, find if there is a number which is majority */
    
    vector<int> numbers1 = {5, 3, 4, 1, 1, 2, 1, 1, 8, 2, 1, 1, 1}; // 1
    vector<int> numbers2 = {5, 3, 4, 1, 1, 2, 1, 1, 8, 2, 3, 5, 6}; // none
    
    // solution 1
    // two for loop
    twoForLoop(numbers1);
    twoForLoop(numbers2);
    
    // solution 2
    // one pass scan
    onePassScanWithMap(numbers1);
    onePassScanWithMap(numbers2);
    
    // solution 3
    // Moorse's Voting Algorithm
    // This algorithm will return the majority number if and only if there is a majority number in set
    mooresVoting(numbers1); // this will work properly
    mooresVoting(numbers2); // this won't work properly
    
    // solution 4
    // binary search
    countWithBST(numbers1);
    countWithBST(numbers2);
    
    
    return 0;
}
