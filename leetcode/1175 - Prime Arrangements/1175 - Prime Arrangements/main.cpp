//
//  main.cpp
//  1175 - Prime Arrangements
//
//  Created by Wu, Meng Ju on 2020/4/18.
//  Copyright © 2020 Pitt. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
private:
    bool isPrime(int num) {
        if (num == 1) { return false; }
        else if (num == 2) { return true; }
        else {
            for (int div = 2; div <= int(sqrt(num)) + 1; div++) {
                if (num % div == 0) {
                    return false;
                }
            }
            return true;
        }
    }
    
    long factorial(int num) {
        long ans = 1;
        long mod = 1000000007;
        for (int i = 1; i < num+1; i++) {
            ans *= i;
            if (ans >= mod) { ans %= mod; }
        }
        return ans;
    }

public:
    int numPrimeArrangements(int n) {
        int Prime=0, notPrime=0;
        
        for (int i = 1; i < n+1; i++) {
            if (isPrime(i)) { Prime++; }
            else { notPrime++; }
        }
        
        return (factorial(notPrime) * factorial(Prime)) % 1000000007;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
