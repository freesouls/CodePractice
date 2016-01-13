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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1){
            return head;
        }
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        ListNode* p = NULL;//, tmp = cur;
        
        while(cur != NULL){
            p = cur;
            bool flag = false;
            for(int i=1; i< k; i++){
                p = p->next;
                if(p == NULL){
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
            ListNode* rest = p->next;
            p->next =NULL;
            
            pre->next = reverseList(cur);
            cur->next = rest;
            
            pre = cur;
            cur = pre->next;
        }
        
        return new_head->next;
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