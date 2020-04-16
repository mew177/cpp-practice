//
//  main.cpp
//  415 - Add Strings
//
//  Created by Wu, Meng Ju on 2020/4/11.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int toInt(char c) {
        return int(c) - int('0');
    }
    
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int i=0, j=0, carry=0;
        int sum=0;
        string total="";
        while (i < num1.size() && j < num2.size()) {
            sum = toInt(num1[i++]) + toInt(num2[j++]) + carry;
            carry = sum / 10;
            total += to_string(sum % 10);
        }
        
        while (i < num1.size()) {
            sum = toInt(num1[i++]) + carry;
            carry = sum / 10;
            total += to_string(sum % 10);
        }
        
        while (j < num2.size()) {
            sum = toInt(num2[j++]) + carry;
            carry = sum / 10;
            total += to_string(sum % 10);
        }
        
        if (carry == 1) {
            total += to_string(carry);
        }
        
        reverse(total.begin(), total.end());
        return total;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
