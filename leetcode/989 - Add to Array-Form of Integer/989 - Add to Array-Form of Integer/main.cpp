//
//  main.cpp
//  989 - Add to Array-Form of Integer
//
//  Created by Wu, Meng Ju on 2020/4/12.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        A[A.size()-1] += K;
        int carry = 0;
        int div = 0;
        for (int i = A.size()-1; i >= 0; i--) {
            div = A[i] % 10;
            carry = A[i] / 10;
            A[i] %= 10;
            if (i > 0) {
                A[i-1] += carry;
            }
        }
        
        while (carry > 0) {
            A.insert(A.begin(), carry % 10);
            carry /= 10;
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
