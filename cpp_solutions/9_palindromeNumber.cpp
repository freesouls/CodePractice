//
//  main.cpp
//  leetcode
//
//  Created by Dirk Xu on 3/31/15.
//  Copyright (c) 2015 Dirk Xu. All rights reserved.
//

#include <iostream>
#include <stdint.h>
class Solution {
public:
   bool isPalindrome(int x) {
        bool flag = false;
        if (x < 0) {
            return flag;
        }
        if (x < 10) {
            return true;
        }
        
        int base = 1;
        int tmp = x;
        
        while (tmp/=10) {
            base*=10;
        }
        
        while (x) {
            int leftDigit = x/base;
            int rightDigit = x%10;
            if (leftDigit != rightDigit) {
                return false;
            }else{
                x %= base;
                x /= 10;
                base /= 100;
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *a = new Solution();
   bool c = a->isPalindrome(1232);    
    return 0;
}
