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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //vector<vector<int> > threeSum(vector<int> &num) {
        
    //}
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n == 0) {
            return head;
        }
        
        ListNode *pPre = NULL;
        ListNode *p = head;
        ListNode *q = head;
        for(int i = 0; i < n - 1; i++)
            q = q->next;
        
        while(q->next)
        {
            pPre = p;
            p = p->next;
            q = q->next;
        }
        
        if (pPre == NULL)
        {
            head = p->next;
        }
        else
        {
            pPre->next = p->next;
        }
        
        return head;
    }    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *a = new Solution();
    //bool b = a->isMatch("aaa", "aa");
    ListNode *b = new ListNode(1);
    //b->next = new ListNode(2);
    //b->next->next = new ListNode(3);
    //b->next->next->next = new ListNode(4);
    ListNode * c = a->removeNthFromEnd(b, 1);
    
    return 0;
}
