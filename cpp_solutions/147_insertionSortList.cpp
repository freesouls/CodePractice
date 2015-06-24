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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        //dummy->next = head; // this step should not be done
        ListNode* node = head;
        while(node != NULL){
        	int val = node->val;
        	ListNode* prev = NULL;
        	ListNode* cur = dummy;
        	for (; cur != NULL && cur->val <= val; prev = cur, cur = cur->next);
        	ListNode* tmp = node->next;
        	node->next = prev->next;
        	prev->next = node;
        	node = tmp;
        }
        return dummy->next;
    }
};