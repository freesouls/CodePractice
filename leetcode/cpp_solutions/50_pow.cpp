//
//  main.cpp
//  leetcode
//
//  Created by Dirk Xu on 3/31/15.
//  Copyright (c) 2015 Dirk Xu. All rights reserved.
//

#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;
class Solution {
public:    
    double pow(double x, int n) {
        if (x == 0.0) {
            return x;
        }
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            x = 1.0/x;
            n = -n;
        }
        
        if (n%2) {
            double tmp = pow(x, n/2);
            return x*tmp*tmp;
        }
        else {
            double tmp = pow(x, n/2);
            return tmp*tmp;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *a = new Solution();
    //bool b = a->isMatch("aaa", "aa");
    double s = a->pow(2.0, -2);
    return 0;
}
