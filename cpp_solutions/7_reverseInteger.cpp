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
    int reverse(int x) {
        int res = 0;
        
        int div = x/10;
        int rem =  x%10;
        while (div) {
            res = res*10 + rem;
            rem = div%10;
            div = div/10;
        }
        
        if ((abs(res)> INT_MAX/10) || (abs(res)==INT_MAX/10 && abs(rem) > INT_MAX%10)) {
            return 0;
        }
        
        return res*10 + rem;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *a = new Solution();
    //int d = a->reverse(-123);
    int c = a->reverse(-2147483648);
    //-2147483648
    //2147483647
    return 0;
}
