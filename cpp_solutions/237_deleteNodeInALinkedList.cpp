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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* t = node->next;
        node->next = t->next;
        delete t;
    }

    void deleteNode2(ListNode* node) {
        if (node == NULL){
            return;
        }
        *node = *node->next;
    }

    void deleteNode1(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};
