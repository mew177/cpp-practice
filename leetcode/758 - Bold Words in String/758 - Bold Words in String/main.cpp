//
//  main.cpp
//  758 - Bold Words in String
//
//  Created by Wu, Meng Ju on 2020/4/15.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        bool mask[S.size()];
        for (int i = 0; i < S.size(); i++) {
            mask[i] = false;
        }
        
        for (string word : words) {
            for (int i = 0; i < S.size(); i++) {
                if (S.substr(i, word.size()) == word) {
                    for (int k = i; k < i+word.size(); k++) {
                        mask[k] = true;
                    }
                }
            }
        }
        
        string ans = "";
        bool onMasked = false;
        for (int i = 0; i < S.size(); i++) {
            if (onMasked && mask[i]) {
                ans += S[i];
            } else if (!onMasked && mask[i]) {
                ans += "<b>";
                ans += S[i];
                onMasked = true;
            } else if (onMasked && !mask[i]) {
                ans += "</b>";
                ans += S[i];
                onMasked = false;
            } else {
                ans += S[i];
            }
        }
        
        if (onMasked) {
            ans += ("</b>");
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
