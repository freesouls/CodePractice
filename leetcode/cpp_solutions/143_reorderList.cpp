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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL){
            return;
        }

        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head, *l2 = slow->next;
        slow->next = NULL;
        l2 = reverseList(l2);
        while(l2){
            ListNode* tmp = l1->next;
            l1->next = l2;
            ListNode* next = l2->next;
            l2->next = tmp;
            l1 = tmp;
            l2 = next;
        }
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
