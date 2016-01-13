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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = NULL, *start = NULL;
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1->val < l2->val){
            start = l1;
            l1 = l1->next;
            p = start;
        }
        else{
            start = l2;
            l2 = l2->next;
            p = start;
        }
        
        while((l1 != NULL)&&(l2 != NULL)){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        if(l1 == NULL && l2 != NULL){
            p->next = l2;
        }
        if(l1 != NULL && l2 == NULL){
            p->next = l1;
        }
        return start;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *a = new Solution();
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(1);
    
    ListNode* d = a->mergeTwoLists(b, c);
    return 0;
}
