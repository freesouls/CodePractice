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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeTwoLists(l1, l2);
    }
    
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