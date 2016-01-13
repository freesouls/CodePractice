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
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Compare {
public:
    bool operator() (ListNode* p, ListNode* q) {
        return p->val > q->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        int n = lists.size();
        // this loop takes O(kLogk) since this is building heap
        for (int i = 0; i < n; ++i) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        ListNode* head = new ListNode(INT_MAX);
        ListNode* runner = head;
        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop(); // O(logk)
            runner->next = top;
            if (top->next) {
                pq.push(top->next); //O(logk)
            }
            runner = runner->next;
            runner->next = NULL;
        }
        return head->next;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *a = new Solution();
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(1);
    
    return 0;
}
