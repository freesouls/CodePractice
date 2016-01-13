/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p1 = head;
        ListNode* p2 = NULL;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* prev = pre;
        int i = 1;
        for(; i < m; ++i){
            prev = p1;
            p1 = p1->next;
        }
        p2 = p1;
        for(; i < n; ++i){
            p2 = p2->next;
        }
        
        ListNode* rest = p2->next;
        p2->next = NULL;
        prev->next = reverseList(p1);
        p1->next = rest;
        
        return pre->next;
    }
    
    ListNode* reverseList(ListNode* cur){
        ListNode* cur_next = NULL;
        ListNode* prev = NULL;
        while(cur != NULL){
            cur_next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = cur_next;
        }
        return prev;
    }
    
};