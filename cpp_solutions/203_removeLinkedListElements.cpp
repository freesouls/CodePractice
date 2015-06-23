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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = new ListNode(1);
        node->next = head;
        ListNode* prev = node;
        ListNode* cur = head;
        while(cur != NULL){
            if (cur->val == val){
                prev->next = cur->next;
            }
            else{
                prev = cur;
                //prev = prev->next; // the same as prev = cur;
            }
            cur = cur->next;
        }
        return node->next;
    }
};