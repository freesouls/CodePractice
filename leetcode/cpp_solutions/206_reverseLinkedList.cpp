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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur_next = NULL;
        ListNode* prev = NULL;
        while(head != NULL){
            cur_next = head->next;
            head->next = prev;
            prev = head;
            head = cur_next;
        }
        return prev;
    }
};