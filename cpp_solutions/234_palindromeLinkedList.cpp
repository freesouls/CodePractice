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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return true;
        }

        ListNode* fast = head, *slow = head, *pre = NULL;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = pre->next;
        pre->next = NULL;
        l2 = reverseList(l2);
        while(l2 && l1){
            if (l2->val != l1->val){
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

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
